#include "piechartadapter.h"

#include <QChart>
#include <QBarSet>
#include <QPieSeries>
#include <QPieSlice>
#include <QStackedBarSeries>
#include <QAbstractItemModel>
#include <QBarSeries>

using namespace QtCharts;

PieChartAdapter::PieChartAdapter(QWidget *parent,const QList<Entry>& data): FilesModel(parent)
{
    const auto series = new QPieSeries;

    //int modelSize = model->rowCount(QModelIndex());

    for (const auto& it : data)
    {

        const auto label = it.entry_name + " - " + QString::number(it.entry_percent* 100, 'g', 3) + "%";

        const auto value = it.entry_percent* 100;

        const auto slice = new QPieSlice(label, value);
        series->append(slice);

    }

    chart.addSeries(series);
    chart.setTheme(QChart::ChartTheme::ChartThemeLight);
    chart.legend()->setAlignment(Qt::AlignRight);



}

void PieChartAdapter::updateModel(QList<Entry> model)
{
    const auto series = new QPieSeries;
    //int modelSize = model->rowCount(QModelIndex());
    for (const auto& it : model)
    {
        const auto label = it.entry_name + " - " + QString::number(it.entry_percent* 100, 'g', 3) + "%";
        const auto value = it.entry_percent* 100;
        const auto set = new QBarSet(label);
        const auto slice = new QPieSlice(label, value);
        series->append(slice);
        set->append(it.entry_percent* 100);
    }

    chart.removeAllSeries();
    chart.addSeries(series);
    chart.setTheme(QChart::ChartTheme::ChartThemeLight);
    chart.legend()->setAlignment(Qt::AlignRight);

}

QChart * PieChartAdapter::getChart()
{
    return &chart;
}

//QChart* ChartAdapter::dataBarChart()
//{

//    //QAbstractItemModel *model = this->model();
//    const auto chart = new QChart;
//    const auto series = new QBarSeries;
//    //int modelSize = model->rowCount(QModelIndex());
//    //
//    for (const auto& it : m_model)
//    {
//
//        const auto label = it.entry_name + " - (" + QString::number(it.entry_percent, 'g', 3) + ")%";
//
//        const auto set = new QBarSet(label);
//
//        set->append(it.entry_percent);
//
//        series->append(set);
//    }

//
//    chart->addSeries(series);
//
//    chart->setTheme(QChart::ChartTheme::ChartThemeQt);
//
//    chart->legend()->setAlignment(Qt::AlignRight);

//
//    return chart;
//}

