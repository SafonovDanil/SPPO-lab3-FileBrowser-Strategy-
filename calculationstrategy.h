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

class CalculationStrategy
{
public:
    CalculationStrategy() = default;
    virtual QList<std::pair<QString,double>> CalculationMethod(const QString&) = 0;
    double fullDirectorySize(QString path);
};

#endif // CALCULATIONSTRATEGY_H
