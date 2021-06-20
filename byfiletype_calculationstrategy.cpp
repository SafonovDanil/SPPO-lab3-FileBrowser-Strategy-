#include "byfiletype_calculationstrategy.h"

QList<std::pair<QString,double>> ByFileType_CalculationStrategy::CalculationMethod(const QString& path)
{
    QDir dir(path);
    QList<std::pair<QString,double>> typesSizeList;
    if(!dir.exists())
        throw QString("directory does not exist");
    QFileInfoList filesInfoList = dir.entryInfoList(QDir::Files);
    QFileInfoList dirList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList::iterator iterFileInfo = dirList.begin();
    for(int i = 0; i < dirList.size(); i++)
    {
        filesInfoList += QDir(dirList[i].absoluteFilePath()).entryInfoList(QDir::Files);
        dirList += QDir(dirList[i].absoluteFilePath()).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    }
    double dirSize = this->fullDirectorySize(path);
    QList <QString> typesList;
    iterFileInfo = filesInfoList.begin();
    while(iterFileInfo != filesInfoList.end())
    {
        if(!typesList.contains(iterFileInfo->suffix()))
            typesList.push_back(iterFileInfo->suffix());
        iterFileInfo++;
    }
    QString curSuffix;
    for (QString &type : typesList)
    {
        curSuffix = type;
        typesSizeList.append(std::pair<QString,double>(curSuffix,0));
        for (QFileInfo &curItem : filesInfoList)
        {
            if(curItem.suffix() == curSuffix)
            typesSizeList.last().second += curItem.size();
        }
    }
    return typesSizeList;
}
