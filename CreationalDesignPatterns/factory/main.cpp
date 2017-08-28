// main.cpp

#include "Factory.hpp"
#include "Product.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    Factory *fac = new ConcreteFactory();
    Product *p = fac->CreateProduct();
    
    return 0;
}