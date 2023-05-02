#include "RPN.hpp"
RPN::RPN(){}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN& RPN::operator=(const RPN &obj)
{
    (void)obj;
    return *this;
}

int RPN::TreatOperand(int n1, int n2, char operation)
{
    if (operation == '+')
        return (n1 + n2);
    else if (operation == '-')
        return (n1 - n2);
    else if (operation == '*')
        return (n1 * n2);
    else if (operation == '/')
    {
        if (n2 == 0)
            throw std::invalid_argument("Can't divide by 0");
        return (n1 / n2);
    }
    return (0);
}

RPN::RPN(std::string arg)
{
   std::string operations = "+-/*";
   int n1 = 0;
   int n2 = 0;
   int num_op = 0;
   int num_num = 0;
   for (size_t i = 0; i < arg.length(); i++)
   {
        if (arg[i] == ' ')
            continue;
        else if (isdigit(arg[i]))
        {
            this->st.push(arg[i] - '0');
            num_num++;
        }
        else if (operations.find(arg[i]) != std::string::npos)
        {
            if (st.empty())
                throw std::invalid_argument("Please check if there are any numbers");
            n1 = st.top();
            st.pop();
            if (st.size() > 0)
            {
                n2 = st.top();
                st.pop();
            }
            else
            {
                std::cout<<"Invalid format !"<<std::endl;
                exit(1);
            }
            st.push(this->TreatOperand(n2, n1, arg[i]));
            num_op++;
        }
        else
            throw std::invalid_argument("Please check if the input is only numbers and allowed operations");
   }
   if (num_num - 1 != num_op)
        throw std::invalid_argument("Please check the operations to numbers ratio");
   std::cout << st.top() << std::endl;
}
RPN::~RPN(){}



// Check number of operators and number of numbers! operator != number - 1 returm;