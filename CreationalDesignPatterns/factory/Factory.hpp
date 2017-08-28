// Factory.hpp

#pragma once

class Product;

class Factory
{
public:
    Factory() = delete;
    virtual~ Factory() = 0;
    virtual Product* CreateProduct() = 0;
};

class ConcreteFactory : public Factory
{
public:
    ConcreteFactory();
    ~ConcreteFactory();
    Product* CreateProduct();
};
