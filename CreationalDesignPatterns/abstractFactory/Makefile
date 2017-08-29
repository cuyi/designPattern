objects = main.o Product.o AbstractFactory.o
main : $(objects)
	g++ -o main $(objects)
mian.o : mian.cpp AbstractFactory.hpp
	g++ -std=c++11 -c main.cpp
Product.o : Product.cpp Product.hpp
	g++ -std=c++11 -c Product.cpp
AbstractFactory.o : AbstractFactory.cpp AbstractFactory.hpp Product.hpp
	g++ -std=c++11 -c AbstractFactory.cpp
clean :
	rm main $(objects)
