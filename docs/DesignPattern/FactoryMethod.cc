/*
意图：定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method 使一个类的实例化延迟到其子类
*/

/* 
问题：这样的方法无非似乎加了层看似没啥用的factory，我要实例对应类的时候任然要实例相应的factory，比如我要实例一个
    Ferrari的车子，我就要先实例化FerrariFactory工厂，然后调用它的create函数。这样我可以不用知道具体的类名是Bike、
    BMW又或者是Ferrari，但是我任然需要知道BikeFactory、BMWFactory、FerrariFactory，这样看起来似乎没什么区别。
    加了这样一个中间层的意义何在呢？

*/
class Car {};
class Bike : public Car {};
class BMW : public Car {};
class Ferrari : public Car {};

class Factory{
public:
    virtual Car* create() = 0;
};

class BikeFactory : public Factory {
public:
    Car* create() {
        return new Bike();
    }
};

class BMWFactory : public Factory {
public:
    Car* create() {
        return new BMW();
    }
};

class FerrariFactory : public Factory {
public:
    Car* create() {
        return new Ferrari();
    }
};

template<typename CarType>
class StandardFactory : public Factory {
public:
    Car* create() {
        return new CarType();
    }
};


int main() {

    Factory *factory = new StandardFactory<Ferrari>();
    Car* car = factory->create(); // 为什么不干脆直接 Car* car = new Ferrari();
    // do something else
    return 0;
}




enum class CarType {Bike, BMW, Ferrari};

// 参数化工厂方法
class CarFactoryWithParameter{

public:
    virtual Car* Create(CarType type) {
        if(type == CarType::Bike) {
            return new Bike;
        }
        else if(type == CarType::BMW) {
            return new BMW;
        }
        else if(type == CarType::Ferrari) {
            return new Ferrari;
        }
        else {
            return nullptr;
        }
    }
};

