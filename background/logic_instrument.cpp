#include "logic_instrument.h"

//template <class widget>
LOGIC_instrument::LOGIC_instrument(LOGIC *L, QObject *parent) : QObject(parent)
{
    LOG = L;
    LOGname[0] = LOG->type();
    LOGname[1] = LOG->controlsId;
}
/*
//template <class widget>
bool LOGIC_instrument<widget>::in_LOGIC(widget* w, LOGIC* L)
{
    if( w->x()-w->boundingRect()->width() > L->x()-L->boundingRect()->width()   //横坐标包含
         && w->x()+w->boundingRect()->width() > L->x()+L->boundingRect()->width()
         && w->y()-w->boundingRect()->height() > L->x()-L->boundingRect()->height() //纵坐标包含
         && w->y()+w->boundingRect()->height() > L->x()+L->boundingRect()->height())
        return true;
    else
        return false;
}
*/
//template <class widget>
bool LOGIC_instrument::widget_make_or_move(widget* w, LOGIC* L)
{//控件生成/拖动/删除时触发
    bool flag = in_LOGIC(w, L);
    if(flag){       //如果在本LOGIC中，就判断是否有内嵌的LOGIC，是否也包含该控件
        widget* p = map_instrument<widget>::find(WidgetsInLOGIC,"LOGIC");
        if(p != NULL){   //如果内部嵌套LOGIC，检查内部的LOGIC是否包含该控件
            if( !(p->LOG_in->widget_make_or_move(w)) ){    //如果内部嵌套的LOGIC不包含该控件，则本LOGIC应该将其添加
                map_instrument<widget>::put_in_map(&WidgetsInLOGIC, w->name, w);
            }
            return true;    //只要该控件在本LOGIC的坐标范围内，就返回true
        }else
            map_instrument<widget>::put_in_map(&WidgetsInLOGIC, w->name, w); //没有内嵌的LOGIC，调用map工具类的方法来添加该控件
    }else{          //如果不在LOGIC中，就调用另一个map工具类的方法来删除该控件
        map_instrument<widget>::del_from_map(&WidgetsInLOGIC, w->name);
        return false;
    }
}


