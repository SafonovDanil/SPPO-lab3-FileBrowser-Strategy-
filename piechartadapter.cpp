#include "piechartadapter.h"

#include <QChart>
#include <QBarSet>
#include <QPieSeries>
#include <QPieSlice>
#include <QStackedBarSeries>
#include <QAbstractItemModel>
#include <QBarSeries>

using namespace QtCharts;

PieChartAdapter::PieChartAdapter(QWidget *parent,const QList<Entry>& data)
{
    chart = new QChart();
}


QAbstractSeries* PieChartAdapter::convertData(QList<Entry> model)
{
    const auto series = new QPieSeries;
    for (const auto& it : model)
    {
        const auto label = it.entry_name + " - " + QString::number(it.entry_percent* 100, 'g', 3) + "%";
        const auto value = it.entry_percent* 100;
        const auto set = new QBarSet(label);
        const auto slice = new QPieSlice(label, value);
        series->append(slice);
        set->append(it.entry_percent* 100);
    }
    return series;
}


void PieChartAdapter::setTheme()
{
    chart->setTheme(QChart::ChartTheme::ChartThemeQt);
//    chart->legend()->setAlignment(Qt::AlignLeft);
}

void PieChartAdapter::setLegend()
{
    chart->legend()->setAlignment(Qt::AlignLeft);
}


QChart * PieChartAdapter::getChart()
{
    return chart;
}


