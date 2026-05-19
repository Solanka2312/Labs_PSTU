#ifndef TRAFFICHART_H
#define TRAFFICHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QVector>
#include <QPointF>

class TrafficChart : public QtCharts::QChartView
{
    Q_OBJECT

public:
    explicit TrafficChart(QWidget *parent = nullptr);
    ~TrafficChart();

    void setHourMode(bool hourMode);
    void setXRange(double min, double max);
    void setYRange(double min, double max);

    void updateLoadCurve(const QVector<QPointF>& curvePoints,
                         double currentIntensity,
                         double currentLoad);
    void setTimeOfDayProfile(const QVector<QPointF>& profile);

private:
    QtCharts::QChart *m_chart;
    QtCharts::QLineSeries *m_curveSeries;
    QtCharts::QScatterSeries *m_currentPoint;
    QtCharts::QLineSeries *m_profileSeries;
    QtCharts::QValueAxis *m_axisX;
    QtCharts::QValueAxis *m_axisY;
};

#endif // TRAFFICHART_H
