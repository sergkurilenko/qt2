#include "imgarraymodel.h"
#include <QDebug>
#include <QColor>

//=====================================
class ImgArrayModelPrivate
{
public:
    QImage data;
};

//--------------------------------------------
ImgArrayModel::ImgArrayModel(QObject *parent)
    : QAbstractTableModel(parent),
     i(new ImgArrayModelPrivate)

{}

ImgArrayModel::ImgArrayModel(const QImage &data, QObject *parent)
    : QAbstractTableModel(parent),
     i(new ImgArrayModelPrivate)
{
    i->data = data;
}

ImgArrayModel::~ImgArrayModel()
{
    delete i;
}

void ImgArrayModel::setModelData(const QImage &data)
{
    beginResetModel();
    i->data = data;
    endResetModel();
}

QImage ImgArrayModel::modelData() const
{
    return i->data;
}

int ImgArrayModel::rowCount(const QModelIndex &index) const
{
    return i->data.height();
}

int ImgArrayModel::columnCount(const QModelIndex &index) const
{
        return i->data.width();
}

QVariant ImgArrayModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    switch(role)
    {

    case Qt::BackgroundRole:
        return (i->data.pixelColor(index.column(), index.row()));
        break;

    case Qt::DisplayRole:
    case Qt::DecorationRole:
    case Qt::FontRole:
    case Qt::TextAlignmentRole:
    case Qt::ForegroundRole:
        break;
    }
    return result;
}

Qt::ItemFlags ImgArrayModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEnabled;
}
