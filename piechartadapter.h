#ifndef PIECHARTADAPTER_H
#define PIECHARTADAPTER_H
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

class PieChartAdapter:public FilesModel
{
public:
    explicit PieChartAdapter(QWidget *parent, const QList<Entry>& data);
    ~PieChartAdapter() = default;
    void updateModel(QList<Entry> model);
    QChart * getChart();
    QtCharts::QChart* dataBarChart();

protected:

private:
    QChart chart;
};
#endif // PIECHARTADAPTER_H
