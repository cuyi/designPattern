// Factory.hpp
#pragma once

class Product;

class Factory
{
public:
    virtual ~Factory() {};
    virtual Product* CreateProduct() = 0;
protected:
    Factory() = default;
};

class ConcreteFactory : public Factory
{
public:
    ConcreteFactory();
    ~ConcreteFactory();
    Product* CreateProduct();
};

