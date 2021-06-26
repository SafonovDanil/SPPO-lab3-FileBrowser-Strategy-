#ifndef PATTERN_H
#define PATTERN_H
#include "entry.h"
#include "imodel.h"
#include <QChart>
#include <QBarSeries>

using namespace QtCharts;
namespace QtCharts
{
    class QChart;
}


class Pattern:public iModel
{
protected:
    QChart* chart;
public:
    Pattern();
    virtual void updateModel(QList<Entry> model);
    virtual QAbstractSeries* convertData(QList<Entry> model) = 0;
    virtual void updateChart(QAbstractSeries* series);
    virtual  void setTheme() = 0;
    virtual void setLegend() = 0;
};

#endif // PATTERN_H
