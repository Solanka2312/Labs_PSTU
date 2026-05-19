#include "mainwindow.h"
#include "trafficcalculator.h"
#include "traffichart.h"
#include "comparedialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QFormLayout>
#include <QSettings>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_currentRoadIndex(-1)
    , m_graphType(0)
{
    setupUI();
    loadRoadsFromSettings();
    updateRoadListWidget();
    loadCalculationSettings();
    loadLastSelectedRoad();
    refreshAllCalculations();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    setWindowTitle("Оценка и прогноз загруженности дорог");
    resize(1000, 700);

    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);
    setCentralWidget(central);

    // Левая панель: управление дорогами
    QGroupBox *roadGroup = new QGroupBox("Дороги");
    QVBoxLayout *roadLayout = new QVBoxLayout(roadGroup);
    m_listWidget = new QListWidget;
    roadLayout->addWidget(m_listWidget);

    QGridLayout *paramsLayout = new QGridLayout;
    paramsLayout->addWidget(new QLabel("Название:"), 0, 0);
    m_editName = new QLineEdit;
    paramsLayout->addWidget(m_editName, 0, 1);
    paramsLayout->addWidget(new QLabel("Длина (км):"), 1, 0);
    m_editLength = new QLineEdit;
    paramsLayout->addWidget(m_editLength, 1, 1);
    paramsLayout->addWidget(new QLabel("Ширина (м):"), 2, 0);
    m_editWidth = new QLineEdit;
    paramsLayout->addWidget(m_editWidth, 2, 1);
    paramsLayout->addWidget(new QLabel("Макс. скорость (км/ч):"), 3, 0);
    m_editSpeed = new QLineEdit;
    paramsLayout->addWidget(m_editSpeed, 3, 1);
    paramsLayout->addWidget(new QLabel("Тип покрытия:"), 4, 0);
    m_comboQuality = new QComboBox;
    m_comboQuality->addItems({"Асфальт", "Грунтовка", "Щебень"});
    paramsLayout->addWidget(m_comboQuality, 4, 1);
    roadLayout->addLayout(paramsLayout);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    m_btnAdd = new QPushButton("Добавить");
    m_btnUpdate = new QPushButton("Обновить");
    m_btnDelete = new QPushButton("Удалить");
    m_btnClear = new QPushButton("Очистить");
    btnLayout->addWidget(m_btnAdd);
    btnLayout->addWidget(m_btnUpdate);
    btnLayout->addWidget(m_btnDelete);
    btnLayout->addWidget(m_btnClear);
    roadLayout->addLayout(btnLayout);
    roadLayout->addStretch();
    mainLayout->addWidget(roadGroup, 1);

    // Панель настроек графика
    QGroupBox *graphControl = new QGroupBox("Настройки графика");
    QVBoxLayout *graphLayout = new QVBoxLayout(graphControl);
    QHBoxLayout *xRangeLayout = new QHBoxLayout;
    xRangeLayout->addWidget(new QLabel("X от"));
    m_xMin = new QDoubleSpinBox;
    m_xMin->setRange(0, 10000);
    m_xMin->setValue(0);
    xRangeLayout->addWidget(m_xMin);
    xRangeLayout->addWidget(new QLabel("до"));
    m_xMax = new QDoubleSpinBox;
    m_xMax->setRange(0, 10000);
    m_xMax->setValue(2000);
    xRangeLayout->addWidget(m_xMax);
    graphLayout->addLayout(xRangeLayout);

    QHBoxLayout *yRangeLayout = new QHBoxLayout;
    yRangeLayout->addWidget(new QLabel("Y от"));
    m_yMin = new QDoubleSpinBox;
    m_yMin->setRange(0, 1);
    m_yMin->setValue(0);
    m_yMin->setSingleStep(0.05);
    yRangeLayout->addWidget(m_yMin);
    yRangeLayout->addWidget(new QLabel("до"));
    m_yMax = new QDoubleSpinBox;
    m_yMax->setRange(0, 1);
    m_yMax->setValue(1);
    m_yMax->setSingleStep(0.05);
    yRangeLayout->addWidget(m_yMax);
    graphLayout->addLayout(yRangeLayout);

    QPushButton *applyRange = new QPushButton("Применить");
    graphLayout->addWidget(applyRange);
    connect(applyRange, &QPushButton::clicked, this, &MainWindow::onApplyRangeClicked);

    m_btnCompare = new QPushButton("Сравнить дороги");
    graphLayout->addWidget(m_btnCompare);
    connect(m_btnCompare, &QPushButton::clicked, this, &MainWindow::onCompareClicked);

    mainLayout->addWidget(graphControl);

    // Правая панель: расчёт
    QGroupBox *calcGroup = new QGroupBox("Расчёт загруженности");
    QVBoxLayout *calcLayout = new QVBoxLayout(calcGroup);

    QGridLayout *inputLayout = new QGridLayout;
    inputLayout->addWidget(new QLabel("Погода:"), 0, 0);
    m_comboWeather = new QComboBox;
    for (auto w : WeatherHelper::allConditions())
        m_comboWeather->addItem(WeatherHelper::toString(w), QVariant::fromValue(w));
    inputLayout->addWidget(m_comboWeather, 0, 1);

    inputLayout->addWidget(new QLabel("Входящий поток (авт/час):"), 1, 0);
    m_spinIntensity = new QSpinBox;
    m_spinIntensity->setRange(0, 10000);
    m_spinIntensity->setValue(500);
    inputLayout->addWidget(m_spinIntensity, 1, 1);

    inputLayout->addWidget(new QLabel("Интервал времени (мин):"), 2, 0);
    m_spinTimeMinutes = new QSpinBox;
    m_spinTimeMinutes->setRange(1, 1440);
    m_spinTimeMinutes->setValue(60);
    inputLayout->addWidget(m_spinTimeMinutes, 2, 1);
    calcLayout->addLayout(inputLayout);

    m_btnCalculate = new QPushButton("Рассчитать");
    m_btnToggleGraph = new QPushButton("Показать суточный прогноз");
    calcLayout->addWidget(m_btnCalculate);
    calcLayout->addWidget(m_btnToggleGraph);

    QGroupBox *resultGroup = new QGroupBox("Результаты");
    QFormLayout *resultLayout = new QFormLayout(resultGroup);
    m_labelCapacity = new QLabel("0");
    m_labelLoad = new QLabel("0%");
    m_labelVehicles = new QLabel("0");
    resultLayout->addRow("Пропускная способность (авт/час):", m_labelCapacity);
    resultLayout->addRow("Загруженность:", m_labelLoad);
    resultLayout->addRow("Машин за интервал:", m_labelVehicles);
    calcLayout->addWidget(resultGroup);
    calcLayout->addStretch();

    mainLayout->addWidget(calcGroup, 1);

    // График
    m_trafficChart = new TrafficChart(this);
    mainLayout->addWidget(m_trafficChart, 3);

    // Сигналы
    connect(m_listWidget, &QListWidget::itemClicked, this, &MainWindow::onRoadListItemClicked);
    connect(m_btnAdd, &QPushButton::clicked, this, &MainWindow::onAddRoadClicked);
    connect(m_btnUpdate, &QPushButton::clicked, this, &MainWindow::onUpdateRoadClicked);
    connect(m_btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteRoadClicked);
    connect(m_btnClear, &QPushButton::clicked, this, &MainWindow::onClearInputClicked);
    connect(m_comboWeather, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onWeatherChanged);
    connect(m_spinIntensity, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onIntensityChanged);
    connect(m_spinTimeMinutes, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onTimeMinutesChanged);
    connect(m_btnCalculate, &QPushButton::clicked, this, &MainWindow::onCalculateClicked);
    connect(m_btnToggleGraph, &QPushButton::clicked, this, &MainWindow::onToggleGraphType);
}

void MainWindow::updateRoadListWidget()
{
    m_listWidget->clear();
    for (const auto &r : m_roads)
        m_listWidget->addItem(r.name());
}

void MainWindow::loadRoadToForm(int index)
{
    if (index < 0 || index >= m_roads.size()) return;
    const RoadSegment &r = m_roads[index];
    m_editName->setText(r.name());
    m_editLength->setText(QString::number(r.lengthKm()));
    m_editWidth->setText(QString::number(r.widthMeters()));
    m_editSpeed->setText(QString::number(r.maxSpeedKmh()));
    QString qStr = qualityToString(r.quality());
    int idx = m_comboQuality->findText(qStr);
    if (idx >= 0) m_comboQuality->setCurrentIndex(idx);
}

RoadSegment MainWindow::getRoadFromForm()
{
    QString name = m_editName->text().trimmed();
    if (name.isEmpty()) name = "Новая дорога";
    double len = m_editLength->text().toDouble();
    double wid = m_editWidth->text().toDouble();
    double spd = m_editSpeed->text().toDouble();
    RoadQuality quality = RoadQuality::Asphalt;
    QString qText = m_comboQuality->currentText();
    if (qText == "Грунтовка") quality = RoadQuality::Gravel;
    else if (qText == "Щебень") quality = RoadQuality::CrushedStone;
    return RoadSegment(name, len, wid, spd, quality);
}

bool MainWindow::validateForm()
{
    bool ok;
    double len = m_editLength->text().toDouble(&ok);
    if (!ok || len <= 0) return false;
    double wid = m_editWidth->text().toDouble(&ok);
    if (!ok || wid <= 0) return false;
    double spd = m_editSpeed->text().toDouble(&ok);
    if (!ok || spd <= 0) return false;
    return true;
}

void MainWindow::refreshAllCalculations()
{
    if (m_currentRoadIndex < 0 || m_currentRoadIndex >= m_roads.size()) return;
    RoadSegment road = m_roads[m_currentRoadIndex];
    WeatherCondition weather = m_comboWeather->currentData().value<WeatherCondition>();
    double weatherCoef = WeatherHelper::coefficient(weather);
    double capacity = TrafficCalculator::effectiveCapacity(road, weatherCoef);
    double intensity = m_spinIntensity->value();
    double load = TrafficCalculator::loadFactor(capacity, intensity);
    int minutes = m_spinTimeMinutes->value();
    int vehicles = TrafficCalculator::vehiclesCount(capacity, intensity, minutes);

    m_labelCapacity->setText(QString::number(capacity, 'f', 0));
    m_labelLoad->setText(QString::number(load * 100, 'f', 1) + "%");
    m_labelVehicles->setText(QString::number(vehicles));

    updateGraph();
}

void MainWindow::updateGraph()
{
    if (m_currentRoadIndex < 0) return;
    RoadSegment road = m_roads[m_currentRoadIndex];
    WeatherCondition weather = m_comboWeather->currentData().value<WeatherCondition>();
    double weatherCoef = WeatherHelper::coefficient(weather);
    double capacity = TrafficCalculator::effectiveCapacity(road, weatherCoef);
    double intensity = m_spinIntensity->value();
    double load = TrafficCalculator::loadFactor(capacity, intensity);

    if (m_graphType == 0) {
        double maxIntensity = capacity * 2.2;
        auto points = TrafficCalculator::loadVsIntensityCurve(road, weatherCoef, maxIntensity, 200);
        m_trafficChart->setHourMode(false);
        m_trafficChart->updateLoadCurve(points, intensity, load);
    } else {
        auto profile = TrafficCalculator::timeOfDayProfile(road, weatherCoef);
        m_trafficChart->setHourMode(true);
        m_trafficChart->setTimeOfDayProfile(profile);
    }
}

void MainWindow::onRoadListItemClicked()
{
    int row = m_listWidget->currentRow();
    if (row >= 0 && row < m_roads.size()) {
        m_currentRoadIndex = row;
        loadRoadToForm(row);
        refreshAllCalculations();
    }
}

void MainWindow::onAddRoadClicked()
{
    if (!validateForm()) {
        QMessageBox::warning(this, "Ошибка", "Введите корректные значения (>0).");
        return;
    }
    RoadSegment newRoad = getRoadFromForm();
    m_roads.append(newRoad);
    updateRoadListWidget();
    m_currentRoadIndex = m_roads.size() - 1;
    m_listWidget->setCurrentRow(m_currentRoadIndex);
    refreshAllCalculations();
    saveRoadsToSettings();
}

void MainWindow::onUpdateRoadClicked()
{
    if (m_currentRoadIndex < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите дорогу.");
        return;
    }
    if (!validateForm()) {
        QMessageBox::warning(this, "Ошибка", "Некорректные параметры.");
        return;
    }
    RoadSegment updated = getRoadFromForm();
    m_roads[m_currentRoadIndex] = updated;
    updateRoadListWidget();
    m_listWidget->setCurrentRow(m_currentRoadIndex);
    refreshAllCalculations();
    saveRoadsToSettings();
}

void MainWindow::onDeleteRoadClicked()
{
    if (m_currentRoadIndex < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите дорогу.");
        return;
    }
    if (QMessageBox::question(this, "Удаление", "Удалить дорогу?") == QMessageBox::Yes) {
        m_roads.removeAt(m_currentRoadIndex);
        m_currentRoadIndex = m_roads.isEmpty() ? -1 : 0;
        updateRoadListWidget();
        if (m_currentRoadIndex >= 0) {
            m_listWidget->setCurrentRow(m_currentRoadIndex);
            loadRoadToForm(m_currentRoadIndex);
        } else {
            m_editName->clear(); m_editLength->clear(); m_editWidth->clear(); m_editSpeed->clear();
        }
        refreshAllCalculations();
        saveRoadsToSettings();
    }
}

void MainWindow::onClearInputClicked()
{
    m_editName->clear();
    m_editLength->clear();
    m_editWidth->clear();
    m_editSpeed->clear();
    m_comboQuality->setCurrentIndex(0);
    m_currentRoadIndex = -1;
    m_listWidget->clearSelection();
}

void MainWindow::onWeatherChanged()
{
    refreshAllCalculations();
}

void MainWindow::onIntensityChanged()
{
    refreshAllCalculations();
}

void MainWindow::onTimeMinutesChanged()
{
    refreshAllCalculations();
}

void MainWindow::onCalculateClicked()
{
    refreshAllCalculations();
}

void MainWindow::onToggleGraphType()
{
    m_graphType = 1 - m_graphType;
    if (m_graphType == 0)
        m_btnToggleGraph->setText("Показать суточный прогноз");
    else
        m_btnToggleGraph->setText("Показать зависимость от интенсивности");
    updateGraph();
}

void MainWindow::onApplyRangeClicked()
{
    if (m_graphType == 0) {
        m_trafficChart->setXRange(m_xMin->value(), m_xMax->value());
    }
    m_trafficChart->setYRange(m_yMin->value(), m_yMax->value());
    updateGraph();
}

void MainWindow::onCompareClicked()
{
    CompareDialog dlg(m_roads, this);
    dlg.exec();
}

// ==================== Сохранение и загрузка ====================

void MainWindow::saveRoadsToSettings()
{
    QSettings settings("RoadTrafficForecast", "Roads");
    settings.beginWriteArray("roads");
    for (int i = 0; i < m_roads.size(); ++i) {
        settings.setArrayIndex(i);
        const RoadSegment &r = m_roads[i];
        settings.setValue("name", r.name());
        settings.setValue("length", r.lengthKm());
        settings.setValue("width", r.widthMeters());
        settings.setValue("maxSpeed", r.maxSpeedKmh());
        settings.setValue("quality", static_cast<int>(r.quality()));
    }
    settings.endArray();
}

void MainWindow::loadRoadsFromSettings()
{
    QSettings settings("RoadTrafficForecast", "Roads");
    int size = settings.beginReadArray("roads");
    m_roads.clear();
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        QString name = settings.value("name", "Новая дорога").toString();
        double length = settings.value("length", 1.0).toDouble();
        double width = settings.value("width", 7.0).toDouble();
        double maxSpeed = settings.value("maxSpeed", 60.0).toDouble();
        RoadQuality quality = static_cast<RoadQuality>(settings.value("quality", 0).toInt());
        m_roads.append(RoadSegment(name, length, width, maxSpeed, quality));
    }
    settings.endArray();

    if (m_roads.isEmpty()) {
        m_roads.append(RoadSegment("Улица Ленина", 2.5, 7.0, 40.0, RoadQuality::Asphalt));
        m_roads.append(RoadSegment("МКАД", 15.0, 10.5, 90.0, RoadQuality::Asphalt));
        m_roads.append(RoadSegment("Лесная грунтовка", 8.0, 4.0, 30.0, RoadQuality::Gravel));
    }
}

void MainWindow::saveCalculationSettings()
{
    QSettings settings("RoadTrafficForecast", "Calculation");
    settings.setValue("weatherIndex", m_comboWeather->currentIndex());
    settings.setValue("intensity", m_spinIntensity->value());
    settings.setValue("timeMinutes", m_spinTimeMinutes->value());
    settings.setValue("graphType", m_graphType);
}

void MainWindow::loadCalculationSettings()
{
    QSettings settings("RoadTrafficForecast", "Calculation");
    int weatherIdx = settings.value("weatherIndex", 0).toInt();
    if (weatherIdx >= 0 && weatherIdx < m_comboWeather->count())
        m_comboWeather->setCurrentIndex(weatherIdx);
    m_spinIntensity->setValue(settings.value("intensity", 500).toInt());
    m_spinTimeMinutes->setValue(settings.value("timeMinutes", 60).toInt());
    m_graphType = settings.value("graphType", 0).toInt();
    if (m_graphType == 0)
        m_btnToggleGraph->setText("Показать суточный прогноз");
    else
        m_btnToggleGraph->setText("Показать зависимость от интенсивности");
}

void MainWindow::saveLastSelectedRoad()
{
    if (m_currentRoadIndex >= 0 && m_currentRoadIndex < m_roads.size()) {
        QSettings settings("RoadTrafficForecast", "LastSelected");
        settings.setValue("lastRoadName", m_roads[m_currentRoadIndex].name());
    }
}

void MainWindow::loadLastSelectedRoad()
{
    QSettings settings("RoadTrafficForecast", "LastSelected");
    QString lastRoadName = settings.value("lastRoadName", "").toString();
    if (!lastRoadName.isEmpty()) {
        for (int i = 0; i < m_roads.size(); ++i) {
            if (m_roads[i].name() == lastRoadName) {
                m_currentRoadIndex = i;
                break;
            }
        }
    }
    if (m_currentRoadIndex == -1 && !m_roads.isEmpty())
        m_currentRoadIndex = 0;
    if (m_currentRoadIndex >= 0) {
        loadRoadToForm(m_currentRoadIndex);
        m_listWidget->setCurrentRow(m_currentRoadIndex);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveRoadsToSettings();
    saveCalculationSettings();
    saveLastSelectedRoad();
    event->accept();
}
