#ifndef BYTEARRAYMODEL_H
#define BYTEARRAYMODEL_H

#include <QObject>
#include <QBitArray>
#include <QAbstractTableModel>

class ByteArrayModelPrivate;
class ByteArrayModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ByteArrayModel(QObject* parent = nullptr);
    ByteArrayModel(const QBitArray& data, QObject* parent = nullptr);
    ~ByteArrayModel();

    void setModelData(const QBitArray& data);

    QBitArray modelData()const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags() const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);



private:
    ByteArrayModelPrivate* m_dptr;
};

#endif // BYTEARRAYMODEL_H
