#ifndef IMGARRAYMODEL_H
#define IMGARRAYMODEL_H

#include <QObject>
#include <QImage>
#include <QAbstractTableModel>

class ImgArrayModelPrivate;
class ImgArrayModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ImgArrayModel(QObject* parent = nullptr);
    ImgArrayModel(const QImage& data, QObject* parent = nullptr);
    ~ImgArrayModel();

    void setModelData(const QImage& data);
    QImage modelData()const;

    int rowCount(const QModelIndex &index) const;
    int columnCount(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;



private:
    ImgArrayModelPrivate* i;
};

#endif // IMGARRAYMODEL_H
