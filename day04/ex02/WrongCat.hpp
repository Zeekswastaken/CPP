#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& ct);
		WrongCat& operator=(const WrongCat &ct);
		void makeSound() const;
};
#endif