#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Incorrect number of arguments" << std::endl;
        exit(1);
    }
    BitcoinExchange bt(argv[1]);

}