#include "piechart.h"

#include "filesmodel.h"

PieChart::PieChart(QWidget *parent) : MyView(parent)
{
}

void PieChart::drawChart(QPainter &painter)
{
    QAbstractItemModel *model = this->model();
    int modelSize = model->rowCount(QModelIndex());
    int startAngle = 0;
    int spanAngle = 0;
    QVector<QColor> colors = rndColors(modelSize);
    for(int i = 0; i < modelSize; i++)
    {
        painter.setPen(colors[i]);
        painter.setBrush(QBrush(colors[i],Qt::SolidPattern));
        double percent = model->data(model->index(i,2),Qt::DisplayRole).toDouble();
        spanAngle = 360 * percent * 16 / 100;
        painter.drawPie(drawRect, startAngle, spanAngle);
        startAngle += spanAngle;
    }
}
