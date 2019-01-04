#include "Object.h"

#include <cstdlib>

namespace HLib
{

void* Object::operator new (unsigned int size) throw()
{
    return malloc(size);
}

void Object::operator delete (void* ptr) throw()
{
    free(ptr);
}

void* Object::operator new[] (unsigned int size) throw()
{
    return malloc(size);
}

void Object::operator delete[] (void* ptr) throw()
{
    free(ptr);
}

Object::~Object() {}

} // HLib
