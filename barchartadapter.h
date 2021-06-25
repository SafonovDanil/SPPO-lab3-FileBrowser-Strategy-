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
    QAbstractSeries* convertData(QList<Entry> model);
};

#endif // CHARTADAPTER_H
