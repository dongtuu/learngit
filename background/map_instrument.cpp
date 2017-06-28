#include "map_instrument.h"
#include <string>

//template <class widget>
map_instrument::map_instrument(QObject *parent) : QObject(parent)
{
    ;
}


//template <class widget>
void map_instrument::map_insert(QMap<QString, widget*>* m, QString index, widget* value)
{
    m->insert(index,value);
}

//template <class widget>
bool map_instrument::put_in_map(QMap<QString, widget*>* m, QString s, widget* w)
{
    typename QMap<QString, widget*>::iterator iter;
    iter = m.find(s);

    if(iter == m.end()){       //如果元素未包含
        map_insert(&m, s, w);
        return true;
    }else
        return false;
}


//template <class widget>
bool map_instrument::del_from_map(QMap<QString, widget*>* m, QString s)
{
    typename QMap<QString, widget*>::iterator iter;
    iter = m.find(s);

    if(iter == m.end()){       //如果元素未包含
        return false;
    }else{
        m.erase(iter);
        return true;
    }

}

//template <class widget>
widget* map_instrument::find(QMap<QString, widget*>* m, QString name = "null")
{
    typename QMap<QString, widget*>::iterator iter;
    for(iter=m->begin();iter!=m->end();iter++){
        if( iter->key.compare(0,5,name)==0 ){  //字符串以"LOGIC"开头
            return iter->value;
        }else
            return NULL;
    }
}
