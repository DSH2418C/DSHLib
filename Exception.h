#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"

namespace HLib
{

#ifndef THROW_EXCEPTION
#define THROW_EXCEPTION(excep, msg) (throw excep(msg, __FILE__, __LINE__))
#endif

/*
 * 异常类的实现决不能抛异常
*/
class Exception : public Object
{
protected:
    char* m_message;
    char* m_location;

    void init(const char* message, const char* file, int line) throw();

public:
    Exception() throw();
    Exception(const char* message) throw();
    Exception(const char* file, int line) throw();
    Exception(const char* message, const char* file, int line) throw();
    Exception(const Exception& except) throw();
    Exception& operator = (const Exception& except) throw();

    virtual const char* message() const throw() { return m_message; }
    virtual const char* location() const throw() { return m_location; }

    virtual ~Exception() = 0;
};


// 计算异常子类
class ArithmeticException : public Exception
{
public:
    ArithmeticException() throw();
    ArithmeticException(const char* message) throw();
    ArithmeticException(const char* file, int line) throw();
    ArithmeticException(const char* message, const char* file, int line) throw();
    ArithmeticException(const ArithmeticException& except) throw();
    ArithmeticException& operator = (const ArithmeticException& except) throw();
};


// 空指针异常子类
class NullPointerException : public Exception
{
public:
    NullPointerException() throw();
    NullPointerException(const char* message) throw();
    NullPointerException(const char* file, int line) throw();
    NullPointerException(const char* message, const char* file, int line) throw();
    NullPointerException(const NullPointerException& except) throw();
    NullPointerException& operator = (const NullPointerException& except) throw();
};


// 越界异常子类
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() throw();
    IndexOutOfBoundsException(const char* message) throw();
    IndexOutOfBoundsException(const char* file, int line) throw();
    IndexOutOfBoundsException(const char* message, const char* file, int line) throw();
    IndexOutOfBoundsException(const IndexOutOfBoundsException& except) throw();
    IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException& except) throw();
};


// 内存不足异常子类
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() throw();
    NoEnoughMemoryException(const char* message) throw();
    NoEnoughMemoryException(const char* file, int line) throw();
    NoEnoughMemoryException(const char* message, const char* file, int line) throw();
    NoEnoughMemoryException(const NoEnoughMemoryException& except) throw();
    NoEnoughMemoryException& operator = (const NoEnoughMemoryException& except) throw();
};


// 参数错误异常子类
class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() throw();
    InvalidParameterException(const char* message) throw();
    InvalidParameterException(const char* file, int line) throw();
    InvalidParameterException(const char* message, const char* file, int line) throw();
    InvalidParameterException(const InvalidParameterException& except) throw();
    InvalidParameterException& operator = (const InvalidParameterException& except) throw();
};


// 非法操作异常子类
class InvalidOperationException : public Exception
{
public:
    InvalidOperationException() throw();
    InvalidOperationException(const char* message) throw();
    InvalidOperationException(const char* file, int line) throw();
    InvalidOperationException(const char* message, const char* file, int line) throw();
    InvalidOperationException(const InvalidOperationException& except) throw();
    InvalidOperationException& operator = (const InvalidOperationException& except) throw();
};

} // HLib


#endif // EXCEPTION_H
