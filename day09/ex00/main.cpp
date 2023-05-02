#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "Incorrect number of arguments" << std::endl;
            exit(1);
        }
        BitcoinExchange bt(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}