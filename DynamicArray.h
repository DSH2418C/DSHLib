#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.h"

namespace HLib
{


/*
 * 动态数组类模板(DynamicSeqList<T,N>)
 * Inherits: Array<T>
 * Bug: 数据元素为Class且无无参构造函数时错误
*/
template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;

public:
    DynamicArray(const int length);
    DynamicArray(const DynamicArray<T>& obj);
    DynamicArray<T>& operator = (const DynamicArray<T>& obj);

    int length() const NO_EXCEPT { return m_length; }

    ~DynamicArray();
};


template<typename T>
DynamicArray<T>::DynamicArray(const int length)
{
    this->m_array = new T[length];

    if( this->m_array )
    {
        m_length = length;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object ...");
    }
}


template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& obj)
{
    this->m_array = new T[obj.m_length];

    if( this->m_array )
    {
        m_length = obj.m_length;

        for( int i=0; i<obj.m_length; ++i )
        {
            this->m_array[i] = obj.m_array[i];
        }
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object ...");
    }
}


template<typename T>
DynamicArray<T>& DynamicArray<T>::operator = (const DynamicArray<T>& obj)
{
    if( this != &obj )
    {
        // 考虑异常安全
        T* tmp = new T[obj.m_length];

        if( tmp )
        {
            for( int i=0; i<obj.m_length; ++i )
            {
                tmp[i] = obj.m_array[i];
            }

            T* array = this->m_array;

            this->m_array = tmp;
            this->m_length = obj.m_length;

            delete[] array;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object ...");
        }
    }

    return *this;
}


template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->m_array;
}


} // HLib

#endif // DYNAMICARRAY_H
