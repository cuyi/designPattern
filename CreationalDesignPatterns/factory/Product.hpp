// Product.hpp
#pragma once

class Product
{
public:
    virtual ~Product() = 0;
    virtual void Operation() = 0;
protected:
    Product() = default;
};

class ConcreteProduct : public Product
{
public:
    ConcreteProduct();
    void Operation();
    ~ConcreteProduct();
};
