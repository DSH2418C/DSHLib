#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include "Exception.h"

namespace HLib
{


/*
 * 顺序表抽象父类模板(SeqList<T>)
 * Inherits: List<T>
 * Inherited By: StaticSeqList<T>, DynamicSeqList<T>
*/
template <typename T>
class SeqList : public List<T>
{
protected:
    T* m_array;
    int m_length;
public:
    bool insert(const int pos, const T& elem);
    bool insert_back(const T& elem);
    bool remove(const int pos);
    bool set(const int pos, const T& elem);
    bool get(const int pos, T& elem) const NO_EXCEPT;
    int length() const NO_EXCEPT;
    void clear() NO_EXCEPT;

    T& operator [] (const int pos) throw(Exception);
    T operator [] (const int pos) const;

    // 最大容量
    virtual int capacity() const = 0;
};


template<typename T>
bool SeqList<T>::insert(const int pos, const T& elem) // O(n)
{
    bool ret = ( (0 <= pos) && (pos <= length()) );
    ret = ret && (length() < capacity());

    if( ret )
    {
        for(int p=length()-1; p>=pos; --p)
        {
            m_array[p + 1] = m_array[p];
        }

        m_array[pos] = elem;
        ++m_length;
    }

    return ret;
}


template<typename T>
bool SeqList<T>::insert_back(const T& elem)
{
    return insert(length(), elem);
}


template<typename T>
bool SeqList<T>::remove(const int pos) // O(n)
{
    bool ret = ( (0 <= pos) && (pos < length()) );

    if( ret )
    {
        for(int p=pos; p<length()-1; ++p)
        {
            m_array[p] = m_array[p + 1];
        }

        --m_length;
    }

    return ret;
}


template<typename T>
bool SeqList<T>::set(const int pos, const T& elem)
{
    bool ret = ( (0 <= pos) && (pos < length()) );

    if( ret )
    {
        m_array[pos] = elem;
    }

    return ret;
}


template<typename T>
bool SeqList<T>::get(const int pos, T& elem) const NO_EXCEPT
{
    bool ret = ( (0 <= pos) && (pos < length()) );

    if( ret )
    {
        elem = m_array[pos];
    }

    return ret;
}


template<typename T>
int SeqList<T>::length() const NO_EXCEPT
{
    return m_length;
}


template<typename T> NO_EXCEPT
void SeqList<T>::clear()
{
    m_length = 0;
}


template<typename T>
T& SeqList<T>::operator [] (const int pos) throw(Exception)
{
    if( (0 <= pos) && (pos < length()) )
    {
        return m_array[pos];
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter pos is invalid...");
    }
}


template<typename T>
T SeqList<T>::operator [] (const int pos) const
{
    return (const_cast<SeqList<T>&>(*this))[pos];
}


} // HLib

#endif // SEQLIST_H
