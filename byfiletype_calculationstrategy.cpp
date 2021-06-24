#include "byfiletype_calculationstrategy.h"

QList<Entry> ByFileType_CalculationStrategy::CalculationMethod(const QString& path)
{
    QDir dir(path);
    QList<Entry> typesSizeList;
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
        typesSizeList.append(Entry(curSuffix,0,0));
        for (QFileInfo &curItem : filesInfoList)
        {
            if(curItem.suffix() == curSuffix)
                typesSizeList.last().entry_size += curItem.size();
        }
        typesSizeList.last().entry_percent = typesSizeList.last().entry_size  / dirSize;
    }
    return typesSizeList;
}
