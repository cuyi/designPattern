// Product.cpp

#include "Product.hpp"
#include <iostream>

using namespace std;

Product::~Product()
{

}

ConcreteProduct::ConcreteProduct()
{
    cout << "ConcreteProduct constructor" << endl;
}

ConcreteProduct::~ConcreteProduct()
{
    cout << "ConcreteProduct destructor" << endl;
}

void ConcreteProduct::Operation()
{
    cout << "ConcreteProduct obj do a specific task" << endl;
}
