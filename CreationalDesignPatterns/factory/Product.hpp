// Product.hpp
#pragma once

class Product
{
public:
    virtual ~Product() {};
protected:
    Product() = default;
};

class ConcreteProduct : public Product
{
public:
    ConcreteProduct();
    ~ConcreteProduct();
};
