#include "comparedialog.h"
#include "trafficcalculator.h"
#include "weatherhelper.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QPainter>

CompareDialog::CompareDialog(const QList<RoadSegment>& roads, QWidget* parent)
    : QDialog(parent), m_roads(roads)
{
    setWindowTitle("Сравнение двух дорог");
    resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(new QLabel("Дорога 1:"));
    m_road1 = new QComboBox;
    topLayout->addWidget(m_road1);
    topLayout->addWidget(new QLabel("Дорога 2:"));
    m_road2 = new QComboBox;
    topLayout->addWidget(m_road2);
    topLayout->addWidget(new QLabel("Погода:"));
    m_weather = new QComboBox;
    for (auto w : WeatherHelper::allConditions())
        m_weather->addItem(WeatherHelper::toString(w), QVariant::fromValue(w));
    topLayout->addWidget(m_weather);
    topLayout->addWidget(new QLabel("Max интенсивность:"));
    m_maxIntensity = new QSpinBox;
    m_maxIntensity->setRange(100, 10000);
    m_maxIntensity->setValue(3000);
    topLayout->addWidget(m_maxIntensity);
    QPushButton *compareBtn = new QPushButton("Сравнить");
    topLayout->addWidget(compareBtn);
    layout->addLayout(topLayout);

    m_chart = new QtCharts::QChart;
    m_chartView = new QtCharts::QChartView(m_chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(m_chartView);

    m_series1 = new QtCharts::QLineSeries;
    m_series1->setName("Дорога 1");
    m_series2 = new QtCharts::QLineSeries;
    m_series2->setName("Дорога 2");
    m_chart->addSeries(m_series1);
    m_chart->addSeries(m_series2);
    m_chart->createDefaultAxes();
    m_chart->axisX()->setTitleText("Интенсивность (авт/час)");
    m_chart->axisY()->setTitleText("Загруженность");
    m_chart->axisY()->setRange(0, 1);

    connect(compareBtn, &QPushButton::clicked, this, &CompareDialog::updateComparison);

    for (int i = 0; i < m_roads.size(); ++i) {
        m_road1->addItem(m_roads[i].name(), i);
        m_road2->addItem(m_roads[i].name(), i);
    }
    if (m_roads.size() >= 2)
        m_road2->setCurrentIndex(1);
    updateComparison();
}

void CompareDialog::updateComparison()
{
    int idx1 = m_road1->currentData().toInt();
    int idx2 = m_road2->currentData().toInt();
    if (idx1 == idx2) return;

    WeatherCondition w = m_weather->currentData().value<WeatherCondition>();
    double weatherCoef = WeatherHelper::coefficient(w);
    int maxInt = m_maxIntensity->value();

    auto points1 = TrafficCalculator::loadVsIntensityCurve(m_roads[idx1], weatherCoef, maxInt, 200);
    auto points2 = TrafficCalculator::loadVsIntensityCurve(m_roads[idx2], weatherCoef, maxInt, 200);

    m_series1->clear();
    m_series2->clear();
    for (auto p : points1) m_series1->append(p);
    for (auto p : points2) m_series2->append(p);

    m_chart->axisX()->setRange(0, maxInt);
}
