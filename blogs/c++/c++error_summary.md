---
title: c++错误汇总
tags:
 - c++
 - error
categories:
 - c++
---
# c++错误汇总


## undefined reference to `vtable for ****'




## 默认参数与重载

```cpp
class test{
private:
    int a;

public:
    test() {a = 10;}
    void print(int a_ = a) { // error: invalid use of non-static data member 'test::a'
        cout << a_ << endl;
    }
};

// solution
class test1{
private:
    int a;

public:
    test() {a = 10;}
    void print() {
        print(a);
    }
    void print(int a_) {
        cout << a_ << endl;
    }
};
```