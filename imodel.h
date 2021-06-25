#ifndef IMODEL_H
#define IMODEL_H
#include <QList>
#include <QChart>
#include <entry.h>

using namespace QtCharts;
namespace QtCharts
{
    class QChart;
}



class iModel

{
public:
    iModel();
    virtual void updateModel(QList<Entry> model) = 0;

};

#endif // IMODEL_H
