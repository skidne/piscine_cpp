#include "span.hpp"

int main()
{
	Span sp = Span(10000);

	srand(time(NULL));
	for (int i = 0; i < 500; i++)
		sp.addNumber(rand() % 10000000);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::vector<int> v;

	for (int i = 500; i < 10000; i++)
		v.push_back(rand() % 10000000);

	sp.addNumberRange(v);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(1232);
	}
	catch (const char * e)
	{
		std::cout << e << std::endl;
	}

	return 0;
}