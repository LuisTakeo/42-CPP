#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string input)
{
    if (input.empty())
        throw std::invalid_argument("Error: empty input");
    this->_input = input;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    if (this == &other)
        return;
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    this->_stack = other._stack;
    this->_input = other._input;
    return *this;
}

void   RPN::pushNumber(std::string &token)
{
    int number = std::atoi(token.c_str());
    if (number >= 10 || token.size() > 1)
        throw std::invalid_argument("Error: Too long number. Use numbers from 0 to 9");
    if (number < 0)
        throw std::invalid_argument("Error: Negative number. Use numbers from 0 to 9");
    this->_stack.push(number);
}

bool    RPN::isOperator(std::string &token)
{
    if (token.size() != 1)
        return false;
    return token[0] == '+' || token[0] == '-'
        || token[0] == '*' || token[0] == '/';
}

int     RPN::getNumberFromStack()
{
    if (this->_stack.empty())
        throw std::logic_error("Error: Stack is empty");
    int number = this->_stack.top();
    this->_stack.pop();
    return number;
}

int     RPN::setOperator(std::string &token)
{
    std::string operators[] = {"+", "-", "*", "/"};
    size_t id;
    for (id = 0; id < operators->size(); id++)
        if (operators[id] == token)
            break;
    return id;
}

void    RPN::putResult(int a, int b, int operatorId)
{
    switch (operatorId)
    {
        case ADD:
            this->_stack.push(a + b);
            break;
        case SUB:
            this->_stack.push(a - b);
            break;
        case MUL:
            this->_stack.push(a * b);
            break;
        case DIV:
            if (b == 0)
                throw std::invalid_argument("Error: Division by zero");
            this->_stack.push(a / b);
            break;
        default:
            throw std::logic_error("Error: Invalid operator");
            break;
    }
}

void    RPN::calculate(std::string &token)
{
    if (this->_stack.size() < 2)
        throw std::invalid_argument("Error: Not enough numbers in stack");
    int a = getNumberFromStack();
    int b = getNumberFromStack();

    std::string operators[] = {"+", "-", "*", "/"};
    int operatorId = setOperator(token);
    putResult(a, b, operatorId);
}

void    RPN::run()
{
    std::string token;
    std::stringstream ss(this->_input);

    while (ss >> token)
    {
        if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1])))
            pushNumber(token);
        else if (isOperator(token))
            calculate(token);
        else
            throw std::invalid_argument("Error: Invalid token");
    }
    if (this->_stack.size() != 1)
        throw std::invalid_argument("Error: Invalid expression");
    std::cout << "Result: " << this->_stack.top() << std::endl;
}