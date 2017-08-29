// Factory.hpp
#pragma once

class Product;

class Factory
{
public:
    virtual ~Factory() = 0;
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

