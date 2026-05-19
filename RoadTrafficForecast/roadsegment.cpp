#include "roadsegment.h"
#include <QtMath>

RoadSegment::RoadSegment()
    : m_name("Новая дорога")
    , m_lengthKm(1.0)
    , m_widthMeters(7.0)
    , m_maxSpeedKmh(60.0)
    , m_quality(RoadQuality::Asphalt)
{
}

RoadSegment::RoadSegment(const QString& name, double lengthKm, double widthMeters, double maxSpeedKmh, RoadQuality quality)
    : m_name(name), m_lengthKm(lengthKm), m_widthMeters(widthMeters), m_maxSpeedKmh(maxSpeedKmh), m_quality(quality)
{
}

QString RoadSegment::name() const { return m_name; }
double RoadSegment::lengthKm() const { return m_lengthKm; }
double RoadSegment::widthMeters() const { return m_widthMeters; }
double RoadSegment::maxSpeedKmh() const { return m_maxSpeedKmh; }
RoadQuality RoadSegment::quality() const { return m_quality; }

void RoadSegment::setName(const QString& name) { m_name = name; }
void RoadSegment::setLengthKm(double km) { if (km > 0) m_lengthKm = km; }
void RoadSegment::setWidthMeters(double m) { if (m > 0) m_widthMeters = m; }
void RoadSegment::setMaxSpeedKmh(double kmh) { if (kmh > 0) m_maxSpeedKmh = kmh; }
void RoadSegment::setQuality(RoadQuality q) { m_quality = q; }

int RoadSegment::laneCount() const
{
    int lanes = static_cast<int>(m_widthMeters / 3.5);
    return (lanes < 1) ? 1 : lanes;
}

double RoadSegment::baseCapacity() const
{
    const double IDEAL_CAPACITY_PER_LANE = 1800.0;
    double speedFactor = qMin(1.0, m_maxSpeedKmh / 50.0);
    return laneCount() * IDEAL_CAPACITY_PER_LANE * speedFactor;
}

double RoadSegment::qualityFactor() const
{
    switch (m_quality) {
        case RoadQuality::Asphalt:      return 1.0;
        case RoadQuality::Gravel:       return 0.4;
        case RoadQuality::CrushedStone: return 0.7;
    }
    return 1.0;
}
