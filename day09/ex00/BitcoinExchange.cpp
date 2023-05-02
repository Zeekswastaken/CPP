#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &an)
{
	(void)an;
	return *this;
}

void BitcoinExchange::Assign(std::string str)
{
    this->date = str.substr(0,10);
    this->value = atof(str.substr(11).c_str());
}

void BitcoinExchange::FillDataBase(void)
{
    std::string str;
    std::ifstream filein;
    filein.open("data.csv");
    getline(filein, str);
    if (filein)
    {
        while(!filein.eof())
        {
            filein >> str;
            this->data.insert(std::make_pair(str.substr(0,10), atof(str.substr(11).c_str())));
        }
    }
}

int check_length(std::string str)
{
    int i = 0;
    std::stringstream line(str);
    std::string token;
    while (line >> token)
    {
        i++;
    }
    return (i);
}

int check_head(std::string str)
{
    std::string token;
    if (check_length(str) != 3)
        return (0);
    std::stringstream line(str);
    line >> token;
    if (token != "date")
        return (0);
    line >> token;
    if (token != "|")
        return (0);
    line >> token;
    if (token != "value")
        return (0);
    return (1);
}

int ft_isdigit(std::string str)
{
    int i = -1;
    while (str[++i])
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

int BitcoinExchange::TreatYear(int year)
{
    if (year < 2009 || year > 2022)
    {
        std::cout << "Error! Please check if the year is between 2009 and 2022" << std::endl;
        return (0);
    }
    return (1);
}

int BitcoinExchange::TreatMonth(int month)
{
    if (month < 1 || month > 12)
    {
        std::cout << "Error! Please check if the month is between 01 and 12" << std::endl;
        return (0);
    }
    return (1);
}

int BitcoinExchange::TreatDay(int day, int month)
{
    int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > arr[month - 1])
    {
        std::cout << "Error! Please check if the day is between 01 and 31" << std::endl;
        return (0);
    }
    return (1);
}

int BitcoinExchange::TreatValue()
{
    if (value < 0.0 || value > 1000.0)
    {
        if (value  > 1000.0)
            std::cout << "Error! Too large of a number" << std::endl;
        else
            std::cout << "Error! Not a positive number." << std::endl;
        return (0);
    }
    return (1);
}

int CheckValue(std::string &token)
{
    int i = -1;
    int point = 0;
    int dash = 0;
    while (token[++i])
    {
        if (token[i] == ',')
            token[i] = '.';
        if (token[i] == '-' && i == 0)
            dash++;
        else if (token[i] == '.')
            point++;
        else if (!isdigit(token[i]))
            return (0);
    }
    if (point > 1 || dash > 1)
        return (0);
    return (1);
}

int BitcoinExchange::Parse_Body(std::string str)
{
    if (check_length(str) != 3)
        return (-1);
    std::stringstream st(str);
    std::string token;
    st >> token;
    int day, month, year;
    if (token.substr(4,1) != "-" || token.substr(7,1) != "-")
    {
        std::cout << "Error! There's a problem with the structure of your file" << std::endl;
        return (0);
    }
    if (!ft_isdigit(token.substr(0,4)) || !ft_isdigit(token.substr(5,2)) || !ft_isdigit(token.substr(8,2)))
        return (0);
    year = atoi(token.substr(0,4).c_str());
    month = atoi(token.substr(5,2).c_str());
    day = atoi(token.substr(8,2).c_str());
    if (!TreatYear(year) || !TreatMonth(month) || !TreatDay(day, month))
        return (0);
    date = token;
    st >> token;
    st >> token;
    if (!CheckValue(token))
        return (-1);
    this->value = std::atof(token.c_str());
    if (!TreatValue())
       return (0);
    return (1);
}

void BitcoinExchange::Calculate()
{
    std::map<std::string, float>::iterator it_b = data.find(date);
    if (it_b != data.end())
        std::cout << date << " => " << value << " = "<< value * it_b->second << std::endl;
    else
    {
        it_b = data.upper_bound(date);
        if (it_b != this->data.begin())
            it_b--;
        std::cout<< date <<" => "<<value<<" = "<<it_b->second * value<<std::endl;
    }
}

BitcoinExchange::BitcoinExchange(std::string file) : value(0.0)
{
    int i = 0;
    std::string str;
    if (file.empty())
    {
        std::cout << "Error! Empty string you must provide an actual file" << std::endl;
        exit(1);
    }
    this->FillDataBase();
    std::ifstream filein;
    filein.open(file);
    int x ;
    if (filein)
    {
            while (getline(filein, str))
            {
                if (i == 0 && check_head(str) == 1)
                    getline(filein, str);
                x = Parse_Body(str);
                if (x != 0)
                {
                    if(x == -1)
                        std::cout << "Error! Bad Input" << std::endl;
                    else
                        Calculate();
                }
                i++;
            }
    }
    else
	{
		std::cout << "Error! Please check if the file exists!" << std::endl;
		exit (1);
	}
}

BitcoinExchange::~BitcoinExchange()
{

}