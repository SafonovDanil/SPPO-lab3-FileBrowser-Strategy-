#ifndef PIECHARTADAPTER_H
#define PIECHARTADAPTER_H
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

class PieChartAdapter:public Pattern
{
public:
    explicit PieChartAdapter(QWidget *parent, const QList<Entry>& data);
    ~PieChartAdapter() = default;
    QChart * getChart();
    virtual QAbstractSeries* convertData(QList<Entry> model);
    virtual void setTheme();
    virtual void setLegend();

protected:

private:
};
#endif // PIECHARTADAPTER_H
