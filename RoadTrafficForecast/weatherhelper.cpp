#include "weatherhelper.h"

double WeatherHelper::coefficient(WeatherCondition weather)
{
    switch (weather) {
        case WeatherCondition::Clear: return 1.0;
        case WeatherCondition::Rain:  return 0.7;
        case WeatherCondition::Fog:   return 0.6;
        case WeatherCondition::Snow:  return 0.4;
    }
    return 1.0;
}

QString WeatherHelper::toString(WeatherCondition weather)
{
    switch (weather) {
        case WeatherCondition::Clear: return "Ясно";
        case WeatherCondition::Rain:  return "Дождь";
        case WeatherCondition::Fog:   return "Туман";
        case WeatherCondition::Snow:  return "Снегопад";
    }
    return "Неизвестно";
}

QList<WeatherCondition> WeatherHelper::allConditions()
{
    return { WeatherCondition::Clear, WeatherCondition::Rain, WeatherCondition::Fog, WeatherCondition::Snow };
}
