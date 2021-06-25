#ifndef IMODEL_H
#define IMODEL_H
#include <QList>

class Entry;

class iModel

{
public:
    iModel();
    virtual void updateModel(QList<Entry> model) = 0;
};

#endif // IMODEL_H
