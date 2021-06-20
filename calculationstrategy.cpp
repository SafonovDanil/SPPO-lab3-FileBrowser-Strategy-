#include "calculationstrategy.h"

double CalculationStrategy::fullDirectorySize(QString path)
{
    double dirSize = 0;
    QDir directory(path);
    QFileInfoList entryList = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for(auto &curItem : entryList)
    {
        if(curItem.isDir())
            dirSize += fullDirectorySize(path + '/' +curItem.fileName());
        else
            dirSize += curItem.size();
    }
    return dirSize;
}
