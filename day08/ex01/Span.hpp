#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
class Span
{
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span &obj);
		void addNumber(int num);
		Span &operator=(const Span &obj);
		int shortestSpan();
		int longestSpan();
		void AddMore(int *begin, int *last);
	private:
		unsigned int	 	N;
		std::vector<int>	vect;
};
#endif