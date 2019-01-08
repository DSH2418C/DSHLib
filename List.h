#ifndef LIST_H
#define LIST_H

#include "Object.h"

namespace HLib
{


/*
 * 线性表抽象父类模板(List<T>)
 * 容器类不允许拷贝构造和拷贝赋值
 * Inherits: Object
 * Inherited By: SeqList
*/
template <typename T>
class List : public Object
{
protected:
    List(const List&);
    List& operator = (const List&);
public:
    List() {}
    virtual bool insert(int pos, const T& elem) = 0;
    virtual bool insert_back(const T& elem) = 0;
    virtual bool remove(int pos) = 0;
    virtual bool set(int pos, const T& elem) = 0;
    virtual bool get(int pos, T& elem) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;
};


} // HLib

#endif // LIST_H
