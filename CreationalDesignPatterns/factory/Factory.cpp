// Factory.cpp

#include "Factory.hpp"
#include "Product"
#include <iostream>

ConcreteFactory::ConcreteFactory()
{
    cout << "ConcreteFactory constructor" << endl;
}

ConcreteFactory::~ConcreteFactory()
{
    cout << "ConcreteFactory destructor" << endl;
}

Product* ConcreteFactory::CtreateProduct()
{
    return new ConcreteProduct();
}
