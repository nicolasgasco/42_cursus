#include "RPN.hpp"

RPN::RPN(std::string const &input)
{
    this->_operators = "+-*/";

    this->_calc_total(input);
}

RPN::~RPN()
{
}

void RPN::_calc_total(std::string const &input)
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

        // Skip an extra space
        if (token.empty() && !tmp.empty())
            continue;
        // Found space at the end of the string
        else if (token.empty() && tmp.empty())
            break;

        if (this->_operators.find(token) != std::string::npos)
            this->_calc_partial_result(token);
        else
        {
            this->_push_operand(token);
        }

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
    // Check that the token is a number
    for (size_t i = 0; i < token.size(); i++)
    {
        if (!isdigit(token[i]) && token[i] != '-')
        {
            this->_set_err_message("Invalid value (not numerical)");
            return;
        }
    }

    float num;
    try
    {
        num = std::stof(token);

        if (token == "5a")
        {
            std::cout << "mierda:" << num << std::endl;
        }
    }
    catch (std::out_of_range &e)
    {
        this->_set_err_message("Invalid value (not an int)");
        return;
    }
    catch (std::invalid_argument &e)
    {
        this->_set_err_message("Invalid value (not numerical)");
        return;
    }

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
        std::cerr << this->_err_message << std::endl;
        return;
    }

    float result = this->_operands.top();
    if (static_cast<int>(result) == result)
        std::cout << result << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}