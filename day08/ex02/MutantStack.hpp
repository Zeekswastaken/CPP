#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
template <typename T>
class MutantStack: public std::stack<T>{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void){};
		~MutantStack(void){};
		MutantStack<T> &operator=(const MutantStack<T> &obj){
			this->c = obj.c;
			return(*this);
		}
		MutantStack(const MutantStack<T> &obj)
		{
			*(this) = obj;
		}
		iterator begin()
		{
			return(this->c.begin());
		}
		iterator end()
		{
			return(this->c.end());
		}
};

#endif