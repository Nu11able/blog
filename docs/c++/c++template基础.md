# c++ template基础

## template定义
```cpp
// 类模板
template<typename T>
class TemplateClass { }

// 函数模板
template<typename T, typename RT = int>
RT TemplateFunction(T &) { }

```

## template特化
```cpp
// 类模板的特化
template<>
class TemplateClass<int> { }

// 显式实例化
template int TemplateFunction(int ) { }


```


## 占坑
### 如何实现对类模板的某个成员函数进行特化
```cpp
// handle.cpp
#include<iostream>

template<typename T1, typename RT = int>
class Test {
public:
    RT operator()();
};

template<typename T1, typename RT>
RT Test<T1, RT>::operator()() {
    std::cout << "This is generic implementation" << std::endl;
    return RT();
}

template<typename RT>
RT Test<int, RT>::operator()() {
    std::cout << "This is int type implementation" << std::endl;
    return RT();
}

int main() {
    Test<char, bool> t1;
    Test<int, int> t2;
    t1();
    t2();
    return 0;
}

/*
.\handle.cpp:16:30: error: invalid use of incomplete type 'class Test<int, RT>'   16 | RT Test<int, RT>::operator()() {
      |                              ^
.\handle.cpp:4:7: note: declaration of 'class Test<int, RT>'
    4 | class Test {
*/


// solution1
#include<iostream>

template<typename T1, typename RT = int>
class Test {
public:
    template<typename _T>
    class TypeTrait {};

    template<typename _T>
    RT Helper(const TypeTrait<_T> &) {
        std::cout << "This is generic implementation" << std::endl;
        return RT();
    }

    RT Helper(const TypeTrait<int> &) {
        std::cout << "This is int type implementation" << std::endl;
        return RT();
    }

    RT operator()() {
        return Helper(TypeTrait<T1>());
    }
};

int main() {
    Test<char, bool> t1;
    Test<int, int> t2;
    t1();
    t2();
    return 0;
}

// solution2

```