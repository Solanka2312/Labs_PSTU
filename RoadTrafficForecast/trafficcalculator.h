#ifndef TRAFFICCALCULATOR_H
#define TRAFFICCALCULATOR_H

#include <QVector>
#include <QPointF>
#include "roadsegment.h"

class TrafficCalculator
{
public:
    static double effectiveCapacity(const RoadSegment& road, double weatherCoef);

    static double loadFactor(double capacity, double inputIntensity, double alpha = 4.0);

    static int vehiclesCount(double capacity, double inputIntensity, int minutes);

    static QVector<QPointF> loadVsIntensityCurve(const RoadSegment& road,
                                                 double weatherCoef,
                                                 double maxIntensity,
                                                 int steps);

    static QVector<QPointF> timeOfDayProfile(const RoadSegment& road,
                                             double weatherCoef);
};

#endif // TRAFFICCALCULATOR_H
