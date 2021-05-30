#include "mainwindow.h"

#include <iostream>
#include <QList>
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QApplication>
#include <QFileSystemModel>
#include <QDebug>


class IStrategy
{
public:
    virtual void CalculationMethod(const QString&) = 0;
    double fullDirectorySize(QString path)
    {
        double direcctorySize = 0;
        QDir directory(path);
        QFileInfoList entryList = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
        for(auto &curItem : entryList)
        {
            if(curItem.isDir())
                direcctorySize += fullDirectorySize(path + '/' +curItem.fileName());
            else
                direcctorySize += curItem.size();
        }
        return direcctorySize;
    }

};

class ByFolder_CalculationStrategy:public IStrategy
{
public:
    void CalculationMethod(const QString& path)
    {
    }
};

class ByFileType_CalculationStrategy:public IStrategy
{
public:
    void CalculationMethod(const QString path){

    };
};

void PrintFolderInfo(QString path, IStrategy* strat)
{
    strat->CalculationMethod(path);
};



int main(int argc, char *argv[])
{
    ByFolder_CalculationStrategy * strat1 = new ByFolder_CalculationStrategy;
    //ByFileType_CalculationStrategy * strat2 = new ByFileType_CalculationStrategy;
    QString path("C:/Users/samiy/Documents/FIFA 21");
    std::cout << std::endl << "strat1:" << std::endl;
    PrintFolderInfo(path, strat1);
    //std::cout << std::endl << "strat2:" << std::endl;
    //PrintFolderInfo(path, strat2);
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
