#include "barchart.h"

#include "filesmodel.h"

BarChart::BarChart(QWidget *parent) : MyView(parent)
{
}

void BarChart::drawChart(QPainter &painter)
{
    QAbstractItemModel *model = this->model();
    int modelSize = model->rowCount(QModelIndex());
    QVector<QColor> colors = rndColors(modelSize);
    for(int i = 0; i < modelSize; i++)
    {
      painter.setPen(QColor(colors[i]));
        painter.setBrush(QBrush(colors[i],Qt::SolidPattern));
        double percent = model->data(model->index(i,2),Qt::DisplayRole).toDouble();
        painter.drawRect(drawRect.x() + 5 + 25*i, drawRect.height() - (drawRect.height() - 10) * percent / 100 ,
                         25, (drawRect.height() - 10) * percent / 100);
    }
}

