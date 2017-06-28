#include "widgetmap.h"

//template <class widget>
WidgetMap<widget>::WidgetMap(QObject *parent) : QObject(parent)
{
    Store = new QMap<QString, widget*>();
    amount = 0;
}

//template <class widget>
void WidgetMap::add(widget* w)
{
    amount++;
    map_instrument::map_insert(&Store, w->name, w);
}

//template <class widget>
void WidgetMap::del(widget* w)
{
    amount--;
    map_instrument<widget>::del_from_map(&Store, w->name);
}


//template <class widget>
QMap<QString, widget*> WidgetMap::get_map()
{
    return Store;
}



