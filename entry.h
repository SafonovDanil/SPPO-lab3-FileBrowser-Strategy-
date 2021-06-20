#ifndef ENTRY_H
#define ENTRY_H

#include <QString>

class Entry
{
public:
    Entry(QString name, double sizePercent, double size);

    QString entry_name;
    double entry_size;
    double entry_percent;
};

#endif // ENTRY_H
