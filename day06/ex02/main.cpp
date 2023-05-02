//#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>


Base *generate(void )
{
	srand(time(0));
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	A *a = dynamic_cast <A *> (p);
	if (a)
		std::cout << "The type is A" << std::endl;
	B *b = dynamic_cast <B *> (p);
	if (b)
		std::cout << "The type is B" << std::endl;
	C *c = dynamic_cast <C *> (p);
	if (c)
		std::cout << "The type is C" << std::endl;
}

void identify(Base &p)
{
	
	try
	{
		A &a = dynamic_cast <A &> (p);
		std::cout << "The type is A" << std::endl;
		(void)a;
	}
	catch(std::bad_cast &e)
	{
		(void)e;
		try
		{
			B &b = dynamic_cast <B &> (p);
			std::cout << "The type is B" << std::endl;
			(void)b;
		}
		catch(std::bad_cast &e){
			(void)e;
			try
			{
				C &c = dynamic_cast <C &> (p);
				std::cout << "The type is C" << std::endl;
				(void)c;
			}
			catch(std::bad_cast &e)
			{
				e.what();
			}
		}
	}
}

int main()
{
	Base *b;
	b = generate();
	identify(b);
	identify(*b);
	delete(b);
}