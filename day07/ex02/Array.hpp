#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array{
	private:
		T *arr;
		int Size;
	public:
		Array(){
			Size = 0;
			arr = NULL;
			std::cout << "Default constructor called" << std::endl;
		}
		Array(unsigned int n)
		{
			if (n < 0)
				throw std::overflow_error("Index is out of bounds");
			this->Size = n;
			this->arr = new T[n]();
		}
		Array (const Array<T> &obj)
		{
			std::cout << "Copy Constructor called" << std::endl;
			this->Size = obj.size();
			if (this->Size > 0)
			{
				this->arr = new T[this->Size];
				for(int i = 0; i < this->Size; i++)
					this->arr[i] = obj.arr[i];
			}
		}
		Array &operator=(const Array<T> &obj)
		{
			
			this->Size = obj.size();
			if (this->Size > 0)
			{
				if (arr)
					delete[] this->arr;
				this->arr = new T[this->Size];
				for(int i = 0; i < this->Size; i++)
					this->arr[i] = obj.arr[i];
			}
			return (*this);
		}
		T &operator[](int i){
			if (i >= this->Size || i < 0)
				throw std::overflow_error("Index is out of bounds");
			return (this->arr[i]);
		}

		int size() const{
			return (this->Size);
		}
		~Array()
		{
			if (this->arr)
				delete [] this->arr;
		}
};
#endif