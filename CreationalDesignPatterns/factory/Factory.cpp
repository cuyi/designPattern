// Factory.cpp

#include "Factory.hpp"
#include "Product.hpp"
#include <iostream>

using namespace std;

Factory::~Factory()
{

}

ConcreteFactory::ConcreteFactory()
{
    cout << "ConcreteFactory constructor" << endl;
}

ConcreteFactory::~ConcreteFactory()
{
    cout << "ConcreteFactory destructor" << endl;
}

Product* ConcreteFactory::CreateProduct()
{
    return new ConcreteProduct();
}
