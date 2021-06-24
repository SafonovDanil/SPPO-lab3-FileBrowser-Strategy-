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
    QtCharts::QChart* dataBarChart();

//    QtCharts::QChart* dataPieChart();
//    QtCharts::QChart* dataStackedBarChart();


//    virtual QModelIndex indexAt(const QPoint &point) const override{return QModelIndex();}
//    virtual void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible) override{}
//    virtual QRect visualRect(const QModelIndex &index) const override{return QRect();}

protected:
//    virtual int horizontalOffset() const override{return 0;}
//    virtual bool isIndexHidden(const QModelIndex &index) const override{return  true;}
//    virtual QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override{return QModelIndex();}
//    virtual void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command) override{};
//    virtual int verticalOffset() const override{return 0;}
//    virtual QRegion visualRegionForSelection(const QItemSelection &selection) const override{return QRegion();}
private:
    QChart chart;
};

#endif // CHARTADAPTER_H
