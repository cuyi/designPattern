objects = main.o Product.o Factory.o
main : $(objects)
	gcc -o main $(objects)
mian.o : mian.cpp Product.hpp Factory.hpp
	gcc -c main.cpp
Product.o : Product.cpp
	gcc -c Product.cpp
Factory.o : Factory.cpp
    g++ -c Factory.cpp
clean :
	rm helloworld $(objects)