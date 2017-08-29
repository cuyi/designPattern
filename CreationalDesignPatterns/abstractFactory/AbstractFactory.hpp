// AbstractFactory.hpp
#pragma once

class AbstractProductA;
class AbstractProductB;

class AbstractFactory{
public:
    virtual ~AbstractFactory();
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;

protected:
    AbstractFactory() = default;
};

class ConcreteFactory1 : public AbstractFactory{
public:
    ConcreteFactory1() = default;
    ~ConcreteFactory1();
    AbstractProductA* CreateProductA() override;
    AbstractProductB* CreateProductB() override;
};

class ConcreteFactory2 : public AbstractFactory{
public:
    ConcreteFactory2() = default;
    ~ConcreteFactory2();
    AbstractProductA* CreateProductA() override;
    AbstractProductB* CreateProductB() override;
};

