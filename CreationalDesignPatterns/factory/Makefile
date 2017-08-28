objects = main.o Product.o Factory.o
main : $(objects)
	g++ -o main $(objects)
mian.o : mian.cpp Product.hpp Factory.hpp
	g++ -std=c++11 -c main.cpp
Product.o : Product.cpp Product.hpp
	g++ -std=c++11 -c Product.cpp
Factory.o : Factory.cpp Factory.hpp
	g++ -std=c++11 -c Factory.cpp
clean :
	rm main $(objects)
