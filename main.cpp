#include "mainwindow.h"

#include <iostream>
#include <QList>
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QApplication>
#include <QFileSystemModel>
#include <QDebug>


//class IStrategy
//{
//public:
//    virtual QList<std::pair<QString,double>> CalculationMethod(const QString&) = 0;
//    double fullDirectorySize(QString path)
//    {
//        double dirSize = 0;
//        QDir directory(path);
//        QFileInfoList entryList = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
//        for(auto &curItem : entryList)
//        {
//            if(curItem.isDir())
//                dirSize += fullDirectorySize(path + '/' +curItem.fileName());
//            else
//                dirSize += curItem.size();
//        }
//        return dirSize;
//    }
//};

//class ByFolder_CalculationStrategy:public IStrategy
//{
//public:
//    QList<std::pair<QString,double>> CalculationMethod(const QString& path)
//    {
//    QDir dir(path);
//    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
//    QList<std::pair<QString,double>> filesSizeList;
//        if(!dir.exists())
//           throw QString("directory does not exist");
//        QFileInfoList filesInfoList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
//        double dirSize = this->fullDirectorySize(path);
//        for (QFileInfo &curItem : filesInfoList)
//        {
//            double itemSize;
//            if(curItem.isDir())
//                itemSize = this->fullDirectorySize(path + '/' +curItem.fileName());
//            else
//                itemSize = (double)curItem.size();
//            filesSizeList.push_back(std::pair<QString,double> (curItem.fileName(),itemSize));
//        }
//        return filesSizeList;
//    }
//};

//class ByFileType_CalculationStrategy:public IStrategy
//{
//public:
//    QList<std::pair<QString,double>> CalculationMethod(const QString& path)
//    {
//        QDir dir(path);
//        //QFileInfoList filesInfoList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
//        QList<std::pair<QString,double>> typesSizeList;
//        if(!dir.exists())
//            throw QString("directory does not exist");
//        QFileInfoList filesInfoList = dir.entryInfoList(QDir::Files);
//        QFileInfoList dirList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
//        QFileInfoList::iterator iterFileInfo = dirList.begin();
//        for(int i = 0; i < dirList.size(); i++)
//        {
//            filesInfoList += QDir(dirList[i].absoluteFilePath()).entryInfoList(QDir::Files);
//            dirList += QDir(dirList[i].absoluteFilePath()).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
//        }
////        while(iterFileInfo != dirList.end())
////        {
////            filesInfoList += QDir(iterFileInfo->absoluteFilePath()).entryInfoList(QDir::Files);
////            dirList += QDir(iterFileInfo->absoluteFilePath()).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
////            iterFileInfo++;
////        }
////        for(auto &curDir : dirList)
////        {
////           filesInfoList += QDir(curDir.absoluteFilePath()).entryInfoList(QDir::Files);
////           dirList += QDir(curDir.absoluteFilePath()).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
////        }
//        double dirSize = this->fullDirectorySize(path);
//        //QFileInfoList::iterator iterFileInfo;
//        QList <QString> typesList;
//        iterFileInfo = filesInfoList.begin();
//        while(iterFileInfo != filesInfoList.end())
//        {
//            if(!typesList.contains(iterFileInfo->suffix()))
//                typesList.push_back(iterFileInfo->suffix());
//            iterFileInfo++;
//        }
//        QString curSuffix;
//        for (QString &type : typesList)
//        {
//            curSuffix = type;
//            typesSizeList.append(std::pair<QString,double>(curSuffix,0));
//            for (QFileInfo &curItem : filesInfoList)
//            {
//                if(curItem.suffix() == curSuffix)
//                typesSizeList.last().second += curItem.size();
//            }
//            //typesSizeList.last().second *= 100;
//        }
//        return typesSizeList;
//        double test = 0;
//        for(auto& curFile : typesSizeList)
//        {
//            test += curFile.second;
//            if (curFile.second >= 0.01)
//                std::cout << curFile.first.toStdString() << "  " <<  (int)(curFile.second*100)/(dirSize*100.)  << " %" << std::endl;
//            else if(curFile.second)
//                std::cout << curFile.first.toStdString() << "  " <<  "<0.01 %"  << std::endl;
//            else
//                std::cout << curFile.first.toStdString() << "  " <<  "0 %"  << std::endl;
//        }
//        if(!test)
//            test = 100;
//        std::cout << "ALL DIR = " << test << " %"<< std::endl;
//        if(typesSizeList.isEmpty())
//        std::cout << "empty directory" << std::endl;
//    }
//};

//void PrintFolderInfo(QString path, IStrategy* strat)
//{
//    QList<std::pair<QString,double>> filesInfoList;
//    filesInfoList = strat->CalculationMethod(path);
//    double test = 0;
//    double dirSize = strat->fullDirectorySize(path);
//    for(auto& curFile : filesInfoList)
//    {
//        test += curFile.second;
//        if (curFile.second >= 0.01)
//            std::cout << curFile.first.toStdString() << "  " <<  (int)((curFile.second/dirSize*100)*100)/(100.)  << " %" << std::endl;
//        else if(curFile.second)
//            std::cout << curFile.first.toStdString() << "  " <<  "<0.01 %"  << std::endl;
//        else
//            std::cout << curFile.first.toStdString() << "  " <<  "0 %"  << std::endl;
//    }
//    test *=  100/dirSize;
//    if(!test)
//        test = 100;
//    std::cout << "ALL DIR " << test << " %" << std::endl;
//    if(filesInfoList.isEmpty())
//        std::cout << "empty directory\n";

//};



int main(int argc, char *argv[])
{
//    ByFolder_CalculationStrategy * strat1 = new ByFolder_CalculationStrategy;
//    ByFileType_CalculationStrategy * strat2 = new ByFileType_CalculationStrategy;

//    QString path("C:/Users/samiy/Documents/SPPO/lab3/test");

//    std::cout << std::endl << "strat1:" << std::endl;
//    PrintFolderInfo(path, strat1);
//    std::cout << std::endl << "strat2:" << std::endl;
//    PrintFolderInfo(path, strat2);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
