#ifndef CHARTADAPTER_H
#define CHARTADAPTER_H
#include <QWidget>
#include <QAbstractItemView>
#include "entry.h"
#include <QChart>
#include "pattern.h"

using namespace QtCharts;
namespace QtCharts
{
    class QChart;
}

class BarChartAdapter:public Pattern
{
public:
    explicit BarChartAdapter(QWidget *parent, const QList<Entry>& data);
    ~BarChartAdapter() = default;
    QChart * getChart();
    virtual QAbstractSeries* convertData(QList<Entry> model);
    virtual void setTheme();
    virtual void setLegend();
};

#endif // CHARTADAPTER_H
