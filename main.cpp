#include "mainwindow.h"

#include <iostream>
#include <QList>
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QApplication>
#include <QFileSystemModel>
class IStrategy
{
public:
    virtual void CalculationMethod(QString) = 0;
};

class ByFolder_CalculationStrategy:public IStrategy
{
public:
    void CalculationMethod(QString path){
}
};

class ByFileType_CalculationStrategy:public IStrategy
{
public:
    void CalculationMethod(QString path){

    };
};

void PrintFolderInfo(QString path, IStrategy* strat)
{
    strat->CalculationMethod(path);
};



int main(int argc, char *argv[])
{
    ByFolder_CalculationStrategy * strat1 = new ByFolder_CalculationStrategy;
    ByFileType_CalculationStrategy * strat2 = new ByFileType_CalculationStrategy;
    QString path("path");
    std::cout << std::endl << "strat1:" << std::endl;
    PrintFolderInfo(path, strat1);
    std::cout << std::endl << "strat2:" << std::endl;
    PrintFolderInfo(path, strat2);
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
