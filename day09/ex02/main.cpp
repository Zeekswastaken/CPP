#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        int i = 1;
        if (argc - 1 > 5)
        {
            std::cout << "Before:";
            while (i < 5)
            {
                std::cout << " " << argv[i];
                i++;
            }
            std::cout << " [...]" << std::endl;
        }
        else
        {
            std::cout << "Before:";
            while (i < argc )
            {
                std::cout << " " << argv[i];
                i++;
            }
            std::cout << std::endl;
        }
        PmergeMe pm(argc, argv);
    }
    else
        std::cout << "Error! Please enter more than one number" << std::endl;
}