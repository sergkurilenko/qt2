#include "bytearraymodel.h"
#include <QDebug>
#include <QColor>

//=====================================
class ByteArrayModelPrivate
{
public:
    QBitArray data;
};

//--------------------------------------------
ByteArrayModel::ByteArrayModel(QObject *parent)
    :  QAbstractTableModel(parent),
      m_dptr(new ByteArrayModelPrivate)
{}

ByteArrayModel::ByteArrayModel(const QBitArray &data, QObject *parent)
    : QAbstractTableModel(parent),
      m_dptr(new ByteArrayModelPrivate)
{
    m_dptr->data = data;
}

ByteArrayModel::~ByteArrayModel()
{
    delete m_dptr;
}

void ByteArrayModel::setModelData(const QBitArray &data)
{
    beginResetModel();
    m_dptr->data = data;
    endResetModel();
}

QBitArray ByteArrayModel::modelData() const
{
    return m_dptr->data;
}

int ByteArrayModel::rowCount(const QModelIndex &parent) const
{
    if(m_dptr->data.size()==0)
        return 0;

    return m_dptr->data.size()/8 + !!(m_dptr->data.size()%8);
}

int ByteArrayModel::columnCount(const QModelIndex &parent) const
{
    if(m_dptr->data.size() < 8)
        return m_dptr->data.size();
    return 8;
}

QVariant ByteArrayModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    switch(role)
    {
    case Qt::DisplayRole:
    {
        int _idx = index.row()*8+index.column();
        if(_idx >= m_dptr->data.size())
            return QVariant();

        int _d  = m_dptr->data.at(_idx);
        result = QString("%1").arg(_d,0,2);
    }
        break;
    case Qt::EditRole:
    case Qt::BackgroundRole:
    case Qt::DecorationRole:
    case Qt::FontRole:
    case Qt::TextAlignmentRole:
    case Qt::ForegroundRole:
        break;
    }
    return result;
}

bool ByteArrayModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool result = false;
    switch(role)
    {
        case Qt::DisplayRole:
        case Qt::EditRole:
        {
            int _idx = index.row()*8+index.column();
            if(_idx < m_dptr->data.size()){
                bool ok  = false;
                int val  = value.toInt(&ok);
                if(ok){
                    m_dptr->data[_idx] = val;
                    result = true;
                }
            }
        }
        break;
    }
    beginResetModel();
    endResetModel();
    return result;
}

Qt::ItemFlags ByteArrayModel::flags() const
{
    return Qt::ItemIsEnabled|Qt::ItemIsEditable;
}
