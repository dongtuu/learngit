#include "digraph.h"
#include "E:/QT_project/workspace/diagram1/Link.h"


/*
 * 这个有向图类可能还存在问题，即当我通过widget指针（祖先类指针）访问子类数据成员时，或许会被拒绝。
 * 需要子类提供一个函数来调用其数据成员。
 * 决定先完成框架，之后再做修缮。
*/
//template<class widget>
digraph::digraph(QObject *parent, QMap<QString, widget *> *m) : QObject(parent)
{
    Map = m;
}

//template<class widget>
std::stack<widget*> digraph::get_topology()
{
    typename QMap<QString, widget*>::iterator it;
    for(it=Map->begin();it!=Map->end();it++){
        DFS(it->value);
    }
    return Stack;
}

//template<class widget>
std::stack<widget*> digraph::get_nodes_without_OUT()
{
    //遍历map，找节点
    std::stack<widget*> sta;  //保存没有出度的节点，返回这个栈对象
    typename QMap<QString, widget*>::iterator it;
    for(it=Map->begin(); it!=Map->end(); ++it){
        if(it->value->yuan->myLinks->isEmpty()){     //没有link
            sta.push(it->value);
        }
    }
    return sta;
}

//template<class widget>
void digraph::DFS(widget* w)
{
    if(visited(w->type())==0){
        visited(w->type())=1;
        QSetIterator<Link*> it(w->yuan->myLinks);   //Qset的迭代器,传入迭代对象
        for(;it.hasNext();){      //遍历每个从当前控件节点指向的节点
            //widget* ww = it.next()->mytoyuan->node;
            DFS(it.next()->toYuan()->node);
        }
        Stack.push(w);  //加入结果集
    }
}











