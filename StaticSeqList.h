#ifndef STATICSEQLIST_H
#define STATICSEQLIST_H

#include "SeqList.h"

namespace HLib
{


/*
 * 静态顺序表类模板(StaticSeqList<T, N>)
 * Inherits: SeqList<T>
 * Bug: 数据元素为Class且无无参构造函数时错误
*/
template <typename T, int N>
class StaticSeqList : public SeqList<T>
{
protected:
    T m_space[N];

public:
    StaticSeqList();
    int capacity() const NO_EXCEPT;
};


template<typename T, int N>
StaticSeqList<T, N>::StaticSeqList()
{
    this->m_array = m_space;
    this->m_length = 0;
}

template<typename T, int N>
int StaticSeqList<T, N>::capacity() const NO_EXCEPT
{
    return N;
}


} // HLib

#endif // STATICSEQLIST_H
