#include <iostream>
#include <cstdlib>
#include <exception>

class Base {

public:
	virtual ~Base() {}

};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *	generate()
{
	Base *ar[] = {new A, new B, new C};
	srand(time(NULL));

	int ind = rand() % 3;
	return ar[ind];
}

void	identify_from_pointer( Base * p )
{
	std::cout << "identify_from_pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else
		std::cout << "C";
	std::cout << std::endl;
}

void	identify_from_reference( Base & p )
{
	A a; B b; C c;

	std::cout << "identify_from_reference: ";

	try
	{
		a = dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch(std::exception e) {}
	try
	{
		b = dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch(std::exception e) {}
	try
	{
		c = dynamic_cast<C &>(p);
		std::cout << "C";
	}
	catch(std::exception e) {}
	
	std::cout << std::endl;
}

int		main()
{
	Base * b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);
	return 0;
}
