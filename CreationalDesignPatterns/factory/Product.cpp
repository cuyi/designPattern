// Product.cpp

#include "Product.hpp"
#include <iostream>

using namespace std;

ConcreteProduct::ConcreteProduct()
{
    cout << "ConreteProduct constructor" << endl;
}

ConreteProduct::~ConcreteProduct()
{
    cout << "ConcreteProduct destructor" << endl;
}
