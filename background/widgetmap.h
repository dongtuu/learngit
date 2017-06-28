#ifndef WIDGETMAP_H
#define WIDGETMAP_H

#include <QObject>
#include <QMap>
#include "map_instrument.h"

/*
 * 这个类用于
 * -保存控件祖先类的指针，间接地保存控件，对所有控件都适用
 */

//template <class widget>
class WidgetMap : public QObject
{
    Q_OBJECT
public:
    explicit WidgetMap(QObject *parent = 0);

    //用于在每次用户创建控件时添加该控件节点，
    void add(widget* w);

    //删除控件
    void del(widget* w);

    QMap<QString, widget*> get_map();

private:
    QMap<QString, widget*> Store;
    int amount;

signals:

public slots:
};

#endif // WIDGETMAP_H
