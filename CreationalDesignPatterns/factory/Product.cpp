// Product.cpp

#include "Product.hpp"
#include <iostream>

using namespace std;

ConcreteProduct::ConcreteProduct()
{
    cout << "ConreteProduct constructor" << endl;
}

ConcreteProduct::~ConcreteProduct()
{
    cout << "ConcreteProduct destructor" << endl;
}
