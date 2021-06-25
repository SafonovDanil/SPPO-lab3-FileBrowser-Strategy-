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
    QAbstractSeries* convertData(QList<Entry> model);

protected:

private:
};
#endif // PIECHARTADAPTER_H
