#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace HLib
{

/*
* 一片堆空间仅能由一个SmartPointer<T>标识
* SmartPointer<T>仅能指向堆空间中单个对象或指针
*/
template <typename T>
class SmartPointer : public Object
{
protected:
    T* m_ptr;

public:
    SmartPointer(T* ptr = NULL);
    SmartPointer(const SmartPointer<T>& obj);
    SmartPointer<T>& operator = (const SmartPointer<T>& obj);

    T* operator -> () const NO_EXCEPT { return m_ptr; }
    T operator * () const NO_EXCEPT { return *m_ptr; }
    bool isNull() const NO_EXCEPT { return !m_ptr; }
    T* getPtr()const NO_EXCEPT { return m_ptr; }

    virtual ~SmartPointer();
};


template<typename T>
SmartPointer<T>::SmartPointer(T* ptr)
    : m_ptr(ptr)
{}


template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& obj)
    : m_ptr(obj.m_ptr)
{
    // 空间所有权转让
    const_cast<SmartPointer<T>&>(obj).m_ptr = NULL;
}


template<typename T>
SmartPointer<T>& SmartPointer<T>::operator = (const SmartPointer<T>& obj)
{
    if( this != &obj )
    {
        delete m_ptr;
        m_ptr = obj.m_ptr;

        const_cast<SmartPointer<T>&>(obj).m_ptr = NULL;
    }

    return *this;
}


template<typename T>
SmartPointer<T>::~SmartPointer()
{
    delete m_ptr;
}

} // HLib

#endif // SMARTPOINTER_H
