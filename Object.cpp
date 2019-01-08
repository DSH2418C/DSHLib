#include "Object.h"

#include <cstdlib>

namespace HLib
{

void* Object::operator new (unsigned long size) NO_EXCEPT
{
    return malloc(size);
}

void Object::operator delete (void* ptr) NO_EXCEPT
{
    free(ptr);
}

void* Object::operator new[] (unsigned long size) NO_EXCEPT
{
    return malloc(size);
}

void Object::operator delete[] (void* ptr) NO_EXCEPT
{
    free(ptr);
}

Object::~Object() {}

} // HLib
