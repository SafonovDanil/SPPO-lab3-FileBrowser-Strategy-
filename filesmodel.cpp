#include "filesmodel.h"
#include <cmath>

#include "byfiletype_calculationstrategy.h"
#include "calculationstrategy.h"
#include "byfolder_calculationstrategy.h"

FilesModel::FilesModel(QObject *parent, QList<Entry> model) : QAbstractTableModel(parent)
{
    m_model = model;
}

int FilesModel::rowCount(const QModelIndex &parent) const
{
    return m_model.count();
}

int FilesModel::columnCount(const QModelIndex &parent) const
{
    return PERCENT + 1;
}

QVariant FilesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Vertical) {
        return section;
    }

    switch (section) {
    case NAME:
        return "Название";
    case SIZE:
        return "Размер";
    case PERCENT:
        return "Процентов";
    }
    return QVariant();
}

QVariant FilesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || m_model.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole))
    {
        return QVariant();
    }

    if (index.column() == 0) {
        return m_model[index.row()].entry_name;
    }
    else if (index.column() == 1) {
        return m_model[index.row()].entry_size;
    }
    else if (index.column() == 2) {
        if(m_model[index.row()].entry_size == 0)
            return 0;
        if(m_model[index.row()].entry_percent*100 > 0.01)
            return std::trunc(m_model[index.row()].entry_percent*10000)/100;
        return "<0,01";
    }
}

void FilesModel::updateModel(QList<Entry> model)
{
    beginResetModel();
    m_model = model;
    endResetModel();
}
