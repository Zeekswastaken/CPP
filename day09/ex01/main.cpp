#include "RPN.hpp"
int main (int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            RPN rp(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cout << "Error in the number of arguments" << std::endl;
        exit (1);
    }
}