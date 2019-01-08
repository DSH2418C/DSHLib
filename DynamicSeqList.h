#ifndef DYNAMICSEQLIST_H
#define DYNAMICSEQLIST_H

#include "SeqList.h"
#include "Exception.h"

namespace HLib
{

/*
 * 动态顺序表类模板(DynamicSeqList<T,N>)
 * Inherits: SeqList<T>
 * Bug: 数据元素为Class且无无参构造函数时错误
*/
template <typename T>
class DynamicSeqList : public SeqList<T>
{
protected:
    int m_capacity;

public:
    DynamicSeqList(const int capacity);

    int capacity() const NO_EXCEPT { return m_capacity; }
    void resize(const int newCapacity);

    ~DynamicSeqList();
};


template<typename T>
DynamicSeqList<T>::DynamicSeqList(const int capacity)
{
    this->m_array = new T[capacity];

    if( this->m_array )
    {
        this->m_length = 0;
        this->m_capacity = capacity;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicSeqList object ...");
    }

}


// 重置空间大小
template<typename T>
void DynamicSeqList<T>::resize(const int newCapacity) // O(n)
{
    if( newCapacity != m_capacity )
    {
        T* array = new T[newCapacity];
        if( array )
        {
            int length = (this->m_length < newCapacity ? this->m_length : newCapacity);

            for(int i=0; i<length; ++i)
            {
                array[i] = this->m_array[i];
            }

            T* tmp = this->m_array;

            this->m_array = array;
            this->m_length = length;
            this->m_capacity = newCapacity;

            delete[] tmp;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to resize DynamicSeqList object ...");
        }
    }
}


template<typename T>
DynamicSeqList<T>::~DynamicSeqList()
{
    delete[] this->m_array;
}


} // HLib

#endif // DYNAMICSEQLIST_H
