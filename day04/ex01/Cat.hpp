#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat: virtual public Animal{
	public:
		Cat();
		~Cat();
		Cat(const Cat& ct);
		Cat& operator=(const Cat &ct);
		virtual void makeSound() const;
	private:
		Brain *br;
};
#endif