#include "Exception.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace HLib
{

//辅助初始化
void Exception::init(const char *message, const char* file, int line) throw()
{
    m_message = message ? strdup(message) : NULL;

    if( file )
    {
        char lineBuf[16] = {0};
        snprintf(lineBuf, sizeof(lineBuf), "%d", line);

        m_location = static_cast<char*>(malloc(strlen(file) + strlen(lineBuf) + 2));
        if( m_location )
        {
            strcpy(m_location, file);
            strcat(m_location, ":");
            strcat(m_location, lineBuf);
        }
    }
    else
    {
        m_location = NULL;
    }
}

Exception::Exception() throw()
    : m_message(NULL), m_location(NULL)
{}

Exception::Exception(const char* message) throw()
{
    init(message, NULL, 0);
}

Exception::Exception(const char* file, int line) throw()
{
    init(NULL, file, line);
}

Exception::Exception(const char* message, const char* file, int line) throw()
{
    init(message, file, line);
}

Exception::Exception(const Exception &except) throw()
    : m_message(strdup(except.m_message)),
      m_location(strdup(except.m_location))
{}

Exception& Exception::operator =(const Exception& except) throw()
{
    if( this != &except )
    {
        free(m_message);
        free(m_location);

        m_message = strdup(except.m_message);
        m_location = strdup(except.m_location);
    }

    return *this;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}


// 计算异常
ArithmeticException::ArithmeticException() throw()
    : Exception() {}

ArithmeticException::ArithmeticException(const char* message) throw()
    : Exception(message) {}

ArithmeticException::ArithmeticException(const char* file, int line) throw()
    : Exception(file, line) {}

ArithmeticException::ArithmeticException(const char *message, const char *file, int line) throw()
    : Exception(message, file, line) {}

ArithmeticException::ArithmeticException(const ArithmeticException& except) throw()
    : Exception(except) {}

ArithmeticException& ArithmeticException::operator =(const ArithmeticException& except) throw()
{
    Exception::operator = (except);

    return *this;
}


// 空指针异常子类
NullPointerException::NullPointerException() throw()
    : Exception() {}

NullPointerException::NullPointerException(const char* message) throw()
    : Exception(message) {}

NullPointerException::NullPointerException(const char* file, int line) throw()
    : Exception(file, line) {}

NullPointerException::NullPointerException(const char *message, const char *file, int line) throw()
    : Exception(message, file, line) {}

NullPointerException::NullPointerException(const NullPointerException& except) throw()
    : Exception(except) {}

NullPointerException& NullPointerException::operator =(const NullPointerException& except) throw()
{
    Exception::operator = (except);

    return *this;
}


// 越界异常子类
IndexOutOfBoundsException::IndexOutOfBoundsException() throw()
    : Exception() {}

IndexOutOfBoundsException::IndexOutOfBoundsException(const char* message) throw()
    : Exception(message) {}

IndexOutOfBoundsException::IndexOutOfBoundsException(const char* file, int line) throw()
    : Exception(file, line) {}

IndexOutOfBoundsException::IndexOutOfBoundsException(const char *message, const char *file, int line) throw()
    : Exception(message, file, line) {}

IndexOutOfBoundsException::IndexOutOfBoundsException(const IndexOutOfBoundsException& except) throw()
    : Exception(except) {}

IndexOutOfBoundsException& IndexOutOfBoundsException::operator =(const IndexOutOfBoundsException& except) throw()
{
    Exception::operator = (except);

    return *this;
}


// 内存不足异常子类
NoEnoughMemoryException::NoEnoughMemoryException() throw()
    : Exception() {}

NoEnoughMemoryException::NoEnoughMemoryException(const char* message) throw()
    : Exception(message) {}

NoEnoughMemoryException::NoEnoughMemoryException(const char* file, int line) throw()
    : Exception(file, line) {}

NoEnoughMemoryException::NoEnoughMemoryException(const char *message, const char *file, int line) throw()
    : Exception(message, file, line) {}

NoEnoughMemoryException::NoEnoughMemoryException(const NoEnoughMemoryException& except) throw()
    : Exception(except) {}

NoEnoughMemoryException& NoEnoughMemoryException::operator =(const NoEnoughMemoryException& except) throw()
{
    Exception::operator = (except);

    return *this;
}


// 参数错误异常子类
InvalidParameterException::InvalidParameterException() throw()
    : Exception() {}

InvalidParameterException::InvalidParameterException(const char* message) throw()
    : Exception(message) {}

InvalidParameterException::InvalidParameterException(const char* file, int line) throw()
    : Exception(file, line) {}

InvalidParameterException::InvalidParameterException(const char *message, const char *file, int line) throw()
    : Exception(message, file, line) {}

InvalidParameterException::InvalidParameterException(const InvalidParameterException& except) throw()
    : Exception(except) {}

InvalidParameterException& InvalidParameterException::operator =(const InvalidParameterException& except) throw()
{
    Exception::operator = (except);

    return *this;
}


// 非法操作异常子类
InvalidOperationException::InvalidOperationException() throw()
    : Exception() {}

InvalidOperationException::InvalidOperationException(const char* message) throw()
    : Exception(message) {}

InvalidOperationException::InvalidOperationException(const char* file, int line) throw()
    : Exception(file, line) {}

InvalidOperationException::InvalidOperationException(const char *message, const char *file, int line) throw()
    : Exception(message, file, line) {}

InvalidOperationException::InvalidOperationException(const InvalidOperationException& except) throw()
    : Exception(except) {}

InvalidOperationException& InvalidOperationException::operator =(const InvalidOperationException& except) throw()
{
    Exception::operator = (except);

    return *this;
}


} // HLib


