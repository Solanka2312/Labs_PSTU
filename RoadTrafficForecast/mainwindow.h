#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QListWidget>
#include "roadsegment.h"
#include "weatherhelper.h"

class TrafficChart;
class CompareDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onRoadListItemClicked();
    void onAddRoadClicked();
    void onUpdateRoadClicked();
    void onDeleteRoadClicked();
    void onClearInputClicked();
    void onWeatherChanged();
    void onIntensityChanged();
    void onTimeMinutesChanged();
    void onCalculateClicked();
    void onToggleGraphType();
    void onApplyRangeClicked();
    void onCompareClicked();

private:
    QList<RoadSegment> m_roads;
    int m_currentRoadIndex;
    int m_graphType;

    TrafficChart *m_trafficChart;

    QDoubleSpinBox *m_xMin, *m_xMax, *m_yMin, *m_yMax;
    QListWidget *m_listWidget;
    QLineEdit *m_editName;
    QLineEdit *m_editLength;
    QLineEdit *m_editWidth;
    QLineEdit *m_editSpeed;
    QComboBox *m_comboQuality;
    QComboBox *m_comboWeather;
    QSpinBox *m_spinIntensity;
    QSpinBox *m_spinTimeMinutes;
    QLabel *m_labelCapacity;
    QLabel *m_labelLoad;
    QLabel *m_labelVehicles;
    QPushButton *m_btnAdd;
    QPushButton *m_btnUpdate;
    QPushButton *m_btnDelete;
    QPushButton *m_btnClear;
    QPushButton *m_btnCalculate;
    QPushButton *m_btnToggleGraph;
    QPushButton *m_btnCompare;

    void setupUI();
    void updateRoadListWidget();
    void loadRoadToForm(int index);
    RoadSegment getRoadFromForm();
    bool validateForm();
    void refreshAllCalculations();
    void updateGraph();

    void saveRoadsToSettings();
    void loadRoadsFromSettings();
    void saveCalculationSettings();
    void loadCalculationSettings();
    void saveLastSelectedRoad();
    void loadLastSelectedRoad();
};

#endif // MAINWINDOW_H
