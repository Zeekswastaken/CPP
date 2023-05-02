#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
class Cat: virtual public Animal{
	public:
		Cat();
		~Cat();
		Cat(const Cat& ct);
		Cat& operator=(const Cat &ct);
		virtual void makeSound() const;
};
#endif