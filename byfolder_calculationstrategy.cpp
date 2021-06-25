#include "byfolder_calculationstrategy.h"
#include "entry.h"

    QList<Entry> ByFolder_CalculationStrategy::CalculationMethod(const QString& path)
    {
    QDir dir(path);
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QList<Entry> filesSizeList;
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
            filesSizeList.push_back(Entry(curItem.fileName(),itemSize,(int)(itemSize*100)/100.*dirSize));
        }
        return filesSizeList;
    }
