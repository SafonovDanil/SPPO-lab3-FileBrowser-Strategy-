#include "barchartadapter.h"

#include <QChart>
#include <QBarSet>
#include <QPieSeries>
#include <QPieSlice>
#include <QStackedBarSeries>
#include <QAbstractItemModel>
#include <QBarSeries>

using namespace QtCharts;

BarChartAdapter::BarChartAdapter(QWidget *parent,const QList<Entry>& data): FilesModel(parent)
{
    chart = new QChart;
//    const auto series = new QBarSeries;
//    for (const auto& it : data)
//    {
//        const auto label = it.entry_name + " - (" + QString::number(it.entry_percent* 100, 'g', 3) + ")%";
//        const auto set = new QBarSet(label);
//        set->append(it.entry_percent* 100);
//        series->append(set);
//    }
//    chart.addSeries(series);
//    chart.setTheme(QChart::ChartTheme::ChartThemeLight);
//    chart.legend()->setAlignment(Qt::AlignRight);

}

void BarChartAdapter::updateModel(QList<Entry> model)
{
    const auto series = new QBarSeries;
    for (const auto& it : model)
    {
        const auto label = it.entry_name + " - " + QString::number(it.entry_percent* 100, 'g', 3) + "%";
        const auto set = new QBarSet(label);
        set->append(it.entry_percent* 100);
        series->append(set);
    }
    chart->removeAllSeries();
    chart->addSeries(series);

    chart->setTheme(QChart::ChartTheme::ChartThemeLight);
    chart->legend()->setAlignment(Qt::AlignRight);

}

QChart * BarChartAdapter::getChart()
{
    return chart;
}
