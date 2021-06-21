#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <iostream>
#include <QList>
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QApplication>
#include <QFileSystemModel>
#include <QDebug>
#include <entry.h>

class CalculationStrategy
{
public:
    CalculationStrategy() = default;
    virtual QList<Entry> CalculationMethod(const QString&) = 0;
    double fullDirectorySize(QString path);
};

#endif // CALCULATIONSTRATEGY_H
