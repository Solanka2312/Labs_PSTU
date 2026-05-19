#include "trafficcalculator.h"
#include <QtMath>

double TrafficCalculator::effectiveCapacity(const RoadSegment& road, double weatherCoef)
{
    return road.baseCapacity() * road.qualityFactor() * weatherCoef;
}

double TrafficCalculator::loadFactor(double capacity, double inputIntensity, double alpha)
{
    if (capacity <= 0.0) return 1.0;
    double ratio = inputIntensity / capacity;
    double load = (alpha * ratio) / (1.0 + alpha * ratio);
    return qMin(1.0, load);
}

int TrafficCalculator::vehiclesCount(double capacity, double inputIntensity, int minutes)
{
    double actualFlow = qMin(inputIntensity, capacity);
    return static_cast<int>(actualFlow * (minutes / 60.0));
}

QVector<QPointF> TrafficCalculator::loadVsIntensityCurve(const RoadSegment& road,
                                                         double weatherCoef,
                                                         double maxIntensity,
                                                         int steps)
{
    QVector<QPointF> points;
    double cap = effectiveCapacity(road, weatherCoef);
    for (int i = 0; i <= steps; ++i) {
        double I = maxIntensity * i / steps;
        points.append(QPointF(I, loadFactor(cap, I)));
    }
    return points;
}

QVector<QPointF> TrafficCalculator::timeOfDayProfile(const RoadSegment& road, double weatherCoef)
{
    QVector<QPointF> profile;
    double capacity = effectiveCapacity(road, weatherCoef);
    if (capacity <= 0) capacity = 1;
    double intensity[24] = {
        80, 50, 40, 30, 40,
        100, 200, 400, 800, 600,
        450, 400, 450, 500, 550,
        600, 750, 850, 700, 500,
        350, 250, 150, 100
    };
    for (int hour = 0; hour < 24; ++hour) {
        double I = qMin(intensity[hour], capacity * 1.5);
        profile.append(QPointF(hour, loadFactor(capacity, I)));
    }
    return profile;
}
