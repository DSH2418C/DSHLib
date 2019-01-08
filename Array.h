#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"
#include "Exception.h"

namespace HLib
{


/*
 * 数组抽象父类模板(Array<T>)
 * Inherits: Object
 * Inherited By: StaticArray<T, N>, DynamicArray<T>
*/
template <typename T>
class Array : public Object
{
protected:
    T* m_array;

public:
    bool set(const int pos, const T& elem);
    bool get(const int pos, T& elem) const NO_EXCEPT;
    T& operator [] (const int pos);
    T operator [] (const int pos) const;
    bool isEmpty() const NO_EXCEPT { return length() == 0; }

    virtual int length() const NO_EXCEPT = 0;
};


template<typename T>
bool Array<T>::set(const int pos, const T& elem)
{
    bool ret = ( (0 <= pos) && (pos < length()) );

    if( ret )
    {
        m_array[pos] = elem;
    }

    return ret;
}


template<typename T>
bool Array<T>::get(const int pos, T& elem) const NO_EXCEPT
{
    bool ret = ( (0 <= pos) && (pos < length()) );

    if( ret )
    {
        elem = m_array[pos];
    }

    return ret;
}


template<typename T>
T& Array<T>::operator [] (const int pos)
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
T Array<T>::operator [] (const int pos) const
{
    return (const_cast<Array<T>&>(*this))[pos];
}


} // HLib

#endif // ARRAY_H
