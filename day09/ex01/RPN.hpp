#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
class RPN
{
    private:
        std::stack<int> st;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        RPN(std::string arg);
        int TreatOperand(int n1, int n2, char operation);
};
#endif