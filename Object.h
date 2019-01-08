#ifndef OBJECT_H
#define OBJECT_H

namespace HLib
{

#ifndef NULL
#define NULL 0
#endif

#ifndef NO_EXCEPT
#define NO_EXCEPT
#endif

/*
 *  创建顶层父类Object统一动态内存规划
*/
class Object
{
public:
    void* operator new (unsigned long size) NO_EXCEPT;
    void operator delete (void* ptr) NO_EXCEPT;
    void* operator new[] (unsigned long size) NO_EXCEPT;
    void operator delete[] (void* ptr) NO_EXCEPT;

    // 方便子类进行动态类型识别
    virtual ~Object() = 0;
};

} // HLib

#endif // OBJECT_H
