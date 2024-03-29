#include "RPN.hpp"

RPN::RPN()
{
    this->_operators = "+-*/";
}

RPN::RPN(std::string const &input)
{
    this->_operators = "+-*/";

    this->_calc_result(input);
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &src)
{
    this->_operators = src._operators;
    return *this;
}

void RPN::_calc_result(std::string const &input)
{

    if (input.empty())
    {
        this->_set_err_message("Please provide a non-empty argument");
        return;
    }

    std::string tmp = input;
    while (1)
    {
        size_t pos = tmp.find(" ");
        std::string token = tmp.substr(0, pos);
        tmp = tmp.substr(pos + 1);

        if (this->_is_space_to_skip(token, tmp))
            continue;
        if (this->_is_trailing_space(token, tmp))
            break;

        if (this->_operators.find(token) != std::string::npos)
            this->_calc_partial_result(token);
        else
            this->_push_operand(token);

        if (pos == std::string::npos || this->_err_message.size())
            break;
    }

    if (this->_operands.size() != 1)
        this->_set_err_message("Invalid expression");
}

void RPN::_calc_partial_result(std::string const &token)
{
    if (this->_operands.size() < 2)
    {
        this->_set_err_message("Invalid expression");
        return;
    }

    float b = this->_operands.top();
    this->_operands.pop();
    float a = this->_operands.top();
    this->_operands.pop();
    // std::cout << "a: " << a << " b: " << b << std::endl;

    float partial_result = -1;
    if (token == "+")
        partial_result = a + b;
    else if (token == "-")
        partial_result = a - b;
    else if (token == "*")
        partial_result = a * b;
    else if (token == "/")
        partial_result = a / b;
    else
    {
        this->_set_err_message("Invalid operator");
        return;
    }

    // std::cout << "partial_result: " << partial_result << std::endl;
    this->_operands.push(partial_result);
}

void RPN::_push_operand(std::string const &token)
{
    if (this->_is_token_numeric(token) == false)
    {
        this->_set_err_message("Invalid value (not numerical)");
        return;
    }

    float num = std::atof(token.c_str());

    if (num >= 10 || num <= -10)
    {
        this->_set_err_message("Invalid value (greather than 9)");
        return;
    }

    this->_operands.push(num);
}

void RPN::_set_err_message(std::string const &err_message)
{
    if (this->_err_message.empty())
        this->_err_message = err_message;
}

void RPN::output_result() const
{
    if (this->_err_message.size())
    {
        std::cout << this->_err_message << std::endl;
        return;
    }

    if (!this->_operands.size())
    {
        std::cout << "Error" << std::endl;
        return;
    }

    float result = this->_operands.top();
    if (static_cast<int>(result) == result)
        std::cout << result << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

void RPN::output_result(std::string const &input)
{
    this->_calc_result(input);

    if (this->_err_message.size())
    {
        std::cout << this->_err_message << std::endl;
        return;
    }

    if (!this->_operands.size())
    {
        std::cout << "Error" << std::endl;
        return;
    }

    float result = this->_operands.top();
    if (static_cast<int>(result) == result)
        std::cout << result << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

bool RPN::_is_space_to_skip(std::string const &token, std::string const &tmp) const
{
    if (token.empty() && !tmp.empty())
        return true;
    return false;
}

bool RPN::_is_token_numeric(std::string const &token) const
{
    for (size_t i = 0; i < token.size(); i++)
    {
        if (!isdigit(token[i]) && token[i] != '-')
            return false;
    }
    return true;
}

bool RPN::_is_trailing_space(std::string const &token, std::string const &tmp) const
{
    if (token.empty() && tmp.empty())
        return true;
    return false;
}
