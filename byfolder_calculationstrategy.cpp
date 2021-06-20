#include "byfolder_calculationstrategy.h"

    QList<std::pair<QString,double>> ByFolder_CalculationStrategy::CalculationMethod(const QString& path)
    {
    QDir dir(path);
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QList<std::pair<QString,double>> filesSizeList;
        if(!dir.exists())
           throw QString("directory does not exist");
        QFileInfoList filesInfoList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
        double dirSize = this->fullDirectorySize(path);
        for (QFileInfo &curItem : filesInfoList)
        {
            double itemSize;
            if(curItem.isDir())
                itemSize = this->fullDirectorySize(path + '/' +curItem.fileName());
            else
                itemSize = (double)curItem.size();
            filesSizeList.push_back(std::pair<QString,double> (curItem.fileName(),itemSize));
        }
        return filesSizeList;
    }
