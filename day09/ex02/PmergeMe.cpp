#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
    vect = obj.vect;
    dq = obj.dq;
    size = obj.size;
    return *this ;
}

int PmergeMe::IsValid(std::string str)
{
    int i = 0;   
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        std::cout << "Error! Please check if every number is positive" << std::endl;
        return (0);
    }
    while (str[i])
    {
        if (!isdigit(str[i]))
        {
            std::cout << "Error! Please check the format of your numbers" << std::endl;
            return (0);
        }
        i++;
    }
    return (1);
}

void PmergeMe::SortDeq(int argc,int beg, int end)
{
    struct timeval start_t, end_t;
    gettimeofday(&start_t, NULL);
    if (beg == end)
        return;
    int mid = (beg + end) / 2;
    SortDeq(argc, beg, mid);
    SortDeq(argc, mid+1, end);
    int i = beg;
    int j = mid + 1;
    int l = (end - beg) + 1;
    std::deque<unsigned int> temp;
    for (int k = 0; k < l; k++){
        if (j > end || (i <= mid && dq[i] < dq[j])){
            temp.push_back(dq[i]);
            i++;
        }
        else{
           temp.push_back(dq[j]);
            j++;
        }
    }
    for (int k = 0, i = beg; k < l; k++, i++)
        dq[i]=temp[k];
    if (temp.size() == size)
    {
        gettimeofday(&end_t, NULL);
        std::cout<<"Time to process a range of "<< (argc - 1) <<" elements with std::deque : "<< static_cast<float>(((end_t.tv_sec - start_t.tv_sec) / 1000000.0) + end_t.tv_usec - start_t.tv_usec) <<" us "<<std::endl;
    }
}

void PmergeMe::SortVect(int argc, int beg, int end)
{
    struct timeval start_t, end_t;
    gettimeofday(&start_t, NULL);
    if (beg == end)
        return;
    int mid = (beg + end) / 2;
    SortVect(argc, beg, mid);
    SortVect(argc, mid+1, end);
    int i = beg ;
    int j = mid + 1;
    int l = (end - beg) + 1;
    std::vector<unsigned int> temp;
    for (int k = 0 ; k < l; k++){
        if (j > end || (i <= mid && vect[i] < vect[j])){
            temp.push_back(vect[i]);
            i++;
        }
        else{
           temp.push_back(vect[j]);
            j++;
        }
    }
    for (int k=0, i=beg; k<l; k++, i++)
        vect[i]=temp[k];
    if (temp.size() == size)
    {
        gettimeofday(&end_t, NULL);
        std::cout<<"Time to process a range of "<< (argc - 1) <<" elements with std::vector : "<< static_cast<float>(((end_t.tv_sec - start_t.tv_sec) / 1000000.0) + end_t.tv_usec - start_t.tv_usec)  <<" us "<<std::endl;
    }
}

void PmergeMe::init_cont(std::string argv)
{
    vect.push_back(std::atoi(argv.c_str()));
    dq.push_back(std::atoi(argv.c_str()));
}

void PmergeMe::Check_sort()
{
    for (std::vector<unsigned int>::iterator it = vect.begin() + 1; it != vect.end(); it++)
    {
        if (*(it - 1) > *it)
            return ;
    }
    std::cout << "The numbers are already sorted" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    int i = 0;
    while (argv[++i])
    {
        if (IsValid(argv[i]) != 0)
            init_cont(argv[i]);
        else
            exit(1);
    }
    Check_sort();
    size = vect.size();
    SortVect(argc, 0, size - 1);
    size = dq.size();
    SortDeq(argc, 0, size - 1);
    i = 0;
    if (argc - 1 > 10)
    {
        std::cout << "After:";
        while (i < 10)
        {
            std::cout << " " << vect[i];
            i++;
        }
        std::cout << " [...]" << std::endl;
    }
    else
    {
        std::cout << "After:";
        while (i < argc - 1)
        {
            std::cout << " " << vect[i];
            i++;
        }
        std::cout << std::endl;
    }
}

PmergeMe::~PmergeMe()
{

}