#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal &an);
		WrongAnimal(const WrongAnimal &an);
		void makeSound() const;
		std::string getType() const;
};
#endif