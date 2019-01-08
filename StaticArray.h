#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "Array.h"

namespace HLib
{


/*
 * 静态数组类模板(StaticArray<T, N>)
 * Inherits: Array<T>
 * Bug: 数据元素为Class且无无参构造函数时错误
*/
template <typename T, int N>
class StaticArray : public Array<T>
{
protected:
    T m_space[N];
public:
    StaticArray();
    StaticArray(const StaticArray<T, N>& obj);
    StaticArray<T, N>& operator = (const StaticArray<T, N>& obj);

    int length() const NO_EXCEPT { return N; }
};


template<typename T, int N>
StaticArray<T, N>::StaticArray()
{
    this->m_array = m_space;
}


template<typename T, int N>
StaticArray<T, N>::StaticArray(const StaticArray<T, N>& obj)
{
    this->m_array = m_space;

    for( int i=0; i<length(); ++i )
    {
        m_space[i] = obj.m_space[i];
    }
}


template<typename T, int N>
StaticArray<T, N>& StaticArray<T, N>::operator = (const StaticArray<T, N>& obj)
{
    if( this != &obj )
    {
        for( int i=0; i<length(); ++i )
        {
            m_space[i] = obj.m_space[i];
        }
    }

    return *this;
}


} // HLib

#endif // STATICARRAY_H
