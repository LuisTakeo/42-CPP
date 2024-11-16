#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

enum operators
{
    ADD = 0,
    SUB,
    MUL,
    DIV
};

class RPN
{
    private:
        std::stack<int> _stack;
        std::string     _input;

        RPN();
        void    pushNumber(std::string &token);
        bool    isOperator(std::string &token);
        void    calculate(std::string &token);
        int     getNumberFromStack();
        int     setOperator(std::string &token);
        void    putResult(int a, int b, int operatorId);

    public:
        RPN(std::string input);
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        void    run();

};

#endif