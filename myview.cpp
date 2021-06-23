#include "myview.h"
#include <QRandomGenerator>
#include <QResizeEvent>


MyView::MyView(QWidget *parent) : QAbstractItemView(parent)
{
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QPalette::Background,Qt::white));
}

void MyView::printLegend(QPainter &painter)
{
    QAbstractItemModel *model = this->model();
    int modelSize = model->rowCount(QModelIndex());
    QVector<QColor> colors = rndColors(modelSize);
    for(int i = 0; i < modelSize; i++)
    {
        painter.setPen(colors[i]);
        painter.setBrush(QBrush(colors[i],Qt::SolidPattern));
        QString text = model->data(model->index(i,0),Qt::DisplayRole).toString();
        text += " (" + model->data(model->index(i,2),Qt::DisplayRole).toString() + "%)";

        painter.drawRect(legendRect.x() + 5, legendRect.y() + 5 + 20*i,10,10);
        painter.setPen(Qt::black);
        painter.drawText(legendRect.x() + 20, legendRect.y() + 15 + 20*i,text);
    }
}

QVector<QColor> MyView::rndColors(int count){
    QVector<QColor> colors;
    float currentHue = 0.0;
    for (int i = 0; i < count; i++){
        colors.push_back( QColor::fromHslF(currentHue, 1.0, 0.5) );
        currentHue += 0.618033988749895f;
        currentHue = std::fmod(currentHue, 1.0f);
    }
    return colors;
}

void MyView::resizeEvent(QResizeEvent *event)
{
    drawRect = QRect(5,5,(event->size().width()-15)*0.8,event->size().height()-10);
    legendRect = QRect(10 + drawRect.width(),5,(event->size().width()-15)*0.2,drawRect.height());
}

void MyView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    //QRandomGenerator random;
    QPainter painter(this->viewport());
    //QColor qc = QColor(qrand() % 255,qrand() % 255,qrand() % 255);
    //painter.setPen(qc);
    drawChart(painter);
    printLegend(painter);
}
