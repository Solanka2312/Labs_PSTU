#ifndef WEATHERHELPER_H
#define WEATHERHELPER_H

#include <QString>
#include <QList>
#include <QMetaType>

enum class WeatherCondition {
    Clear,
    Rain,
    Fog,
    Snow
};
Q_DECLARE_METATYPE(WeatherCondition)

class WeatherHelper
{
public:
    static double coefficient(WeatherCondition weather);
    static QString toString(WeatherCondition weather);
    static QList<WeatherCondition> allConditions();
};

#endif // WEATHERHELPER_H
