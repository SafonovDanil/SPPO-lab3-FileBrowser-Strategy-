#ifndef CHARTADAPTER_H
#define CHARTADAPTER_H
#include <QWidget>
#include <QAbstractItemView>
#include "entry.h"
#include <QChart>
#include "filesmodel.h"
using namespace QtCharts;
namespace QtCharts
{
    class QChart;
}

class BarChartAdapter:public FilesModel
{
public:
    explicit BarChartAdapter(QWidget *parent, const QList<Entry>& data);
    ~BarChartAdapter() = default;
    void updateModel(QList<Entry> model);
    QChart * getChart();

private:
    QChart chart;
};

#endif // CHARTADAPTER_H
