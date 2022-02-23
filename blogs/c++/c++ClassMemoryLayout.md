---
title: c++类内存分布分析
tags:
 - c++
categories:
 - c++
---
# c++类内存分布分析

## 类的大小

### 基础类的大小
在c语言里面一个struct的大小就它所包含的所有成员大小的和，那么在c++里面呢？考虑下面的例子:
```cpp
#include<iostream>
using namespace std;

class A {
public:
    void func1() {}
    void func2() {}

    int a;
    int b;
    double c;
};

int main() {
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    return 0;
}
/* 输出
sizeof(int): 4
sizeof(double): 8
sizeof(A): 16
*/

```
**类的大小为类成员的大小之和(不包含成员函数)**，从这一点可以发现和c语言的类有些类似。
> only data members got the space

### 继承类的大小
```cpp
#include<iostream>
using namespace std;

//取消注释改行关闭数据对其
//#pragma pack(1)

class A {
public:
    void func1() {}
    void func2() {}

    int a;
    int b;
    double c;
    static int d;
};

class B : public A{
public:
    int d;
};

int main() {
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(B): " << sizeof(B) << endl;
    return 0;
}
/* 输出
sizeof(int): 4
sizeof(double): 8
sizeof(A): 16
sizeof(B): 24
*/
```
看到sizeof(B)的大小为24可能会令人感到疑惑，这是由于编译器开启了内存对齐，我的是64位系统所以编译器会按8byte对齐。另外为何sizeof(A)的大小为16而不是20呢，对于静态数据成员它有专门的存放地区，后面我们会提到。到此我们就可以得出结论了：**只有类数据成员才会被分配内存**

## 参考链接、书籍
[Memory Layout of C++ Object in Different Scenarios](http://www.vishalchovatiya.com/memory-layout-of-cpp-object/)

《深度探索C++对象模型》