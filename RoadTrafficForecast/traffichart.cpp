#include "traffichart.h"
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLegend>
#include <QPen>
#include <cmath>

using namespace QtCharts;

TrafficChart::TrafficChart(QWidget *parent)
    : QChartView(parent)
    , m_chart(new QChart())
    , m_curveSeries(new QLineSeries())
    , m_currentPoint(new QScatterSeries())
    , m_profileSeries(nullptr)
{
    m_curveSeries->setName("Зависимость загруженности");
    QPen pen(Qt::blue);
    pen.setWidth(2);
    m_curveSeries->setPen(pen);

    m_currentPoint->setName("Текущий режим");
    m_currentPoint->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    m_currentPoint->setMarkerSize(10);
    m_currentPoint->setColor(Qt::red);

    m_chart->addSeries(m_curveSeries);
    m_chart->addSeries(m_currentPoint);

    m_axisX = new QValueAxis();
    m_axisX->setTitleText("Интенсивность (авт/час)");
    m_axisX->setLabelFormat("%.0f");
    m_axisY = new QValueAxis();
    m_axisY->setTitleText("Загруженность (0..1)");
    m_axisY->setRange(0, 1);
    m_axisY->setTickCount(6);

    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    m_curveSeries->attachAxis(m_axisX);
    m_curveSeries->attachAxis(m_axisY);
    m_currentPoint->attachAxis(m_axisX);
    m_currentPoint->attachAxis(m_axisY);

    m_chart->setTitle("Оценка загруженности дороги");
    m_chart->legend()->setVisible(true);
    m_chart->legend()->setAlignment(Qt::AlignBottom);
    setChart(m_chart);
    setRenderHint(QPainter::Antialiasing);
}

TrafficChart::~TrafficChart() {}

void TrafficChart::setHourMode(bool hourMode)
{
    if (hourMode) {
        m_axisX->setTitleText("Время (часы)");
        m_axisX->setRange(0, 23);
        m_axisX->setLabelFormat("%.0f");
        m_axisX->setTickCount(7);
    } else {
        m_axisX->setTitleText("Интенсивность (авт/час)");
    }
}

void TrafficChart::setXRange(double min, double max)
{
    m_axisX->setRange(min, max);
    // Подбираем красивый интервал меток
    double range = max - min;
    double step = range / 5.0;
    if (step < 100) step = 100;
    else if (step < 200) step = 200;
    else if (step < 500) step = 500;
    else if (step < 1000) step = 1000;
    else step = std::round(step / 1000) * 1000;
    m_axisX->setTickInterval(step);
    m_axisX->setTickAnchor(0);
}

void TrafficChart::setYRange(double min, double max)
{
    m_axisY->setRange(min, max);
}

void TrafficChart::updateLoadCurve(const QVector<QPointF>& curvePoints,
                                   double currentIntensity,
                                   double currentLoad)
{
    m_curveSeries->clear();
    for (const QPointF &p : curvePoints)
        m_curveSeries->append(p);
    m_currentPoint->clear();
    m_currentPoint->append(currentIntensity, currentLoad);

    if (!curvePoints.isEmpty()) {
        double maxX = curvePoints.last().x();
        m_axisX->setRange(0, maxX);
        double step = maxX / 5.0;
        if (step < 100) step = 100;
        else if (step < 200) step = 200;
        else if (step < 500) step = 500;
        else if (step < 1000) step = 1000;
        else step = std::round(step / 1000) * 1000;
        m_axisX->setTickInterval(step);
        m_axisX->setTickAnchor(0);
        m_axisX->setLabelFormat("%.0f");
    }
}

void TrafficChart::setTimeOfDayProfile(const QVector<QPointF>& profile)
{
    if (!m_profileSeries) {
        m_profileSeries = new QLineSeries();
        QPen pen(Qt::darkGreen);
        pen.setWidth(2);
        pen.setStyle(Qt::DashLine);
        m_profileSeries->setPen(pen);
        m_profileSeries->setName("Суточный прогноз");
        m_chart->addSeries(m_profileSeries);
        m_profileSeries->attachAxis(m_axisX);
        m_profileSeries->attachAxis(m_axisY);
    }
    m_profileSeries->clear();
    for (const QPointF &p : profile)
        m_profileSeries->append(p);
}
