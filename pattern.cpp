#include "pattern.h"
#include <QBarSet>

Pattern::Pattern()
{

}

void Pattern::updateModel(QList<Entry> model)
{
    auto series = convertData(model);
    updateChart(series);
}
 void Pattern::updateChart(QAbstractSeries* series)
 {
     chart->removeAllSeries();
     chart->addSeries(series);
     this->setTheme();
     this->setLegend();
 }
