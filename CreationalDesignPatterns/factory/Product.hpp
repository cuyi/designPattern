// Product.hpp
#pragma once

class Product
{
public:
    Product() = delete;
    virtual ~Product() = 0;
};

class ConcreteProduct : public Product
{
public:
    ConcreteProduct();
    ~ConcreteProduct();
};
