#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <deque>
#include <sys/time.h>
class PmergeMe{
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        ~PmergeMe();
        void SortVect(int argc,int beg, int end);
        void SortDeq(int argc,int beg, int end);
        int IsValid(std::string str);
        void init_cont(std::string argv);
        void Check_sort();
    private:
        std::vector<unsigned int> vect;
        std::deque<unsigned int> dq;
        unsigned int size;
};
#endif