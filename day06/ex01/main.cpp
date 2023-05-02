#include "Serialization.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast <Data*>(raw);
}

int main()
{
	Data *lol = new Data();
	uintptr_t test;
	lol->data = "Idk what to say";
	test = serialize(lol);
	std::cout << "After the serialization ======== " << test << std::endl;
	Data *lol2 = deserialize(test);
	std::cout << "Data pointer === " << lol2->data << std::endl;
}