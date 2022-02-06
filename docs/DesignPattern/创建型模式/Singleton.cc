/*
意图：保证一个类仅有一个实例，并提供一个访问它的全局访问点
*/
#include<map>

using namespace std;

// --------------------- Singleton.cpp ---------------------
class Singleton {
public:
    static Singleton* Instance() {
        if(m_instance == nullptr) {
            m_instance = new Singleton();
        }
        return m_instance;
    }

protected:
    // 将构造函数声明为保护型的，防止直接实例化，保证一个类只有一个实例
    Singleton(); 

private:
    static Singleton* m_instance; // 保存该实例的指针
};

Singleton* Singleton::m_instance = nullptr;


// --------------------- MySingleton1.cpp ---------------------

class MySingleton1 : public Singleton {

};