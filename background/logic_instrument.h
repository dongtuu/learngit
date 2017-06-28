#ifndef LOGIC_INSTRUMENT_H
#define LOGIC_INSTRUMENT_H


#include <QObject>
#include <QMap>
#include <QString>
#include "map_instrument.h"
#include "E:/QT_project/workspace/diagram1/rec.h"
typedef Rec LOGIC;

/*
 * 这个类用于
 * -即时判断LOGIC包含哪些控件，同时存储这些控件
 * --当一个LOGIC被创建时，对应的创建一个LOGIC_instrument，它保存这个LOGIC的内含控件。
 * --当一个控件(不包含本LOGIC)被创建、移动时，发送信号给所有的LOGIC_instrument，它们判断这个控件是否在本LOGIC的xy坐标范围内，
 *   如果是，则保存这个控件，否则不理睬。
*/
//template <class widget>
class LOGIC_instrument : public QObject
{
    Q_OBJECT
public:

    explicit LOGIC_instrument(LOGIC* L, QObject *parent = 0);

    //判断是否某个控件是否在某个LOGIC内部。LOGIC是LOGIC类对象
    static bool in_LOGIC(widget* w, LOGIC* L);

private:

    QMap<QString, widget*> WidgetsInLOGIC;
    LOGIC* LOG;     //指向对应的LOGIC
    int LOGname[1]; //保存LOG的名字

signals:

public slots:
    bool widget_make_or_move(widget *w, LOGIC *L);
};

#endif // LOGIC_INSTRUMENT_H
