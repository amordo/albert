// Copyright (c) 2023 Manuel Schneider

#pragma once
#include "albert/extension.h"
#include <QAbstractListModel>
#include <QIcon>
#include <map>
#include <memory>
#include <vector>
class QueryBase;
namespace albert{
class Item;
class RankItem;
}

class ItemsModel : public QAbstractListModel
{
public:
    ItemsModel(QObject *parent = nullptr); // important for qml cppownership

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void add(albert::Extension*, const std::shared_ptr<albert::Item>&);
    void add(albert::Extension*, std::shared_ptr<albert::Item>&&);

    void add(albert::Extension*, const std::vector<std::shared_ptr<albert::Item>>&);
    void add(albert::Extension*, std::vector<std::shared_ptr<albert::Item>>&&);

    void add(std::vector<std::pair<albert::Extension*,albert::RankItem>>::iterator begin,
             std::vector<std::pair<albert::Extension*,albert::RankItem>>::iterator end);

    QAbstractListModel *buildActionsModel(uint i) const;
    void activate(QueryBase *q, uint i, uint a);

private:
    std::vector<std::pair<albert::Extension*, std::shared_ptr<albert::Item>>> items;
};
