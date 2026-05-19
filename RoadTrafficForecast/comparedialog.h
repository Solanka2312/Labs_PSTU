#ifndef COMPAREDIALOG_H
#define COMPAREDIALOG_H

#include <QDialog>
#include <QList>
#include "roadsegment.h"

class QComboBox;
class QSpinBox;
class QPushButton;

namespace QtCharts {
    class QChartView;
    class QChart;
    class QLineSeries;
}

class CompareDialog : public QDialog
{
    Q_OBJECT
public:
    CompareDialog(const QList<RoadSegment>& roads, QWidget* parent = nullptr);
private slots:
    void updateComparison();
private:
    QList<RoadSegment> m_roads;
    QComboBox *m_road1, *m_road2;
    QComboBox *m_weather;
    QSpinBox *m_maxIntensity;
    QtCharts::QChartView *m_chartView;
    QtCharts::QChart *m_chart;
    QtCharts::QLineSeries *m_series1, *m_series2;
};

#endif // COMPAREDIALOG_H
