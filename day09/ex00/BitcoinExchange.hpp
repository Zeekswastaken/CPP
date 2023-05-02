#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>
class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        std::string date;
        float value;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange(std::string file);
        BitcoinExchange &operator=(const BitcoinExchange &an);
        void FillDataBase(void);
        void Assign(std::string str);
        int Parse_Body(std::string str);
        int TreatYear(int year);
        int TreatMonth(int month);
        int TreatDay (int day, int month);
        int TreatValue();
        void Calculate();
        ~BitcoinExchange();
};
#endif