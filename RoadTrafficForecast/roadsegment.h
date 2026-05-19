#ifndef ROADSEGMENT_H
#define ROADSEGMENT_H

#include <QString>

enum class RoadQuality {
    Asphalt,
    Gravel,
    CrushedStone
};

inline QString qualityToString(RoadQuality q) {
    switch (q) {
        case RoadQuality::Asphalt: return "Асфальт";
        case RoadQuality::Gravel:  return "Грунтовка";
        case RoadQuality::CrushedStone: return "Щебень";
    }
    return "Неизвестно";
}

class RoadSegment
{
public:
    RoadSegment();
    RoadSegment(const QString& name, double lengthKm, double widthMeters, double maxSpeedKmh, RoadQuality quality);

    QString name() const;
    double lengthKm() const;
    double widthMeters() const;
    double maxSpeedKmh() const;
    RoadQuality quality() const;

    void setName(const QString& name);
    void setLengthKm(double km);
    void setWidthMeters(double m);
    void setMaxSpeedKmh(double kmh);
    void setQuality(RoadQuality q);

    int laneCount() const;
    double baseCapacity() const;
    double qualityFactor() const;

private:
    QString m_name;
    double m_lengthKm;
    double m_widthMeters;
    double m_maxSpeedKmh;
    RoadQuality m_quality;
};

#endif // ROADSEGMENT_H
