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
    QDir dir(path);
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QList<std::pair<QString,double>> filesSizeList;
    if(!path.isEmpty())
        {
            if(!dir.exists())
                throw QString("Directory does not exist");
            QFileInfoList filesInfoList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
            double dirSize = this->fullDirectorySize(path);
            for (QFileInfo &curItem : filesInfoList)
            {
                double itemSize;
                if(curItem.isDir())
                    itemSize = this->fullDirectorySize(path + '/' +curItem.fileName())/dirSize;
                else
                    itemSize = (double)curItem.size()/dirSize;
                filesSizeList.push_back(std::pair<QString,double> (curItem.fileName(),itemSize));
            }
        }
        //std::cout << curDir.fileName().toStdString() << ":\n";
        for(auto& curFile : filesSizeList)
        {
            if (curFile.second >= 0.01)
                std::cout << curFile.first.toStdString() << "  " <<  (int)(curFile.second*100)/100.  << " %" << std::endl;
            else if(curFile.second)
                std::cout << curFile.first.toStdString() << "  " <<  "<0.01 %"  << std::endl;
            else
                std::cout << curFile.first.toStdString() << "  " <<  "0 %"  << std::endl;
        }
        if(filesSizeList.isEmpty())
            std::cout << "empty directory\n";








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
