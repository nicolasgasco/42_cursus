#include "RPN.hpp"

RPN::RPN()
{
    this->_has_err = false;
}

RPN::~RPN()
{
    this->_has_err = false;
}

void RPN::_parse_input(std::string const &input)
{
    std::string tmp = input;

    if (input.empty())
    {
        this->_has_err = true;
        return;
    }

    std::string signs[4] = {"+", "-", "*", "/"};

    while (tmp.size() > 0)
    {
        size_t index = tmp.size();
        size_t signs_len = (sizeof(signs) / sizeof(std::string));
        for (size_t i = 0; i < signs_len; ++i)
        {
            size_t found_index = tmp.find_first_of(signs[i]);
            if (found_index != std::string::npos && found_index < index)
                index = found_index;
        }

        std::string operation = (tmp[0] == ' ') ? tmp.substr(1, index + 1) : tmp.substr(0, index + 1);
        this->_ops.push(operation);

        try
        {
            // Remove parsed operation
            tmp = tmp.substr(index + 1);
        }
        catch (std::exception &e)
        {
            this->_has_err = true;
            return;
        }
    }
}

void RPN::calculate(std::string const &input)
{
    this->_parse_input(input);

    if (this->_has_err)
    {
        std::cerr << "Error";
        return;
    }

    int sum = 0;
    bool is_first_run = true;
    for (size_t i = 0; i < this->_ops.size(); ++i)
    {
        std::string current_ops = this->_ops.front();
        std::queue<int> ops_values;

        while (1)
        {
            std::cout << "current op: ." << current_ops << "." << std::endl;
            // If string is not correctly trimmed
            int start = current_ops.find_first_not_of(" ");
            current_ops = current_ops.substr(start);

            int end = current_ops.find_first_of(" ");
            std::string value = current_ops.substr(0, end);

            bool value_is_sign = value == "+" || value == "-" || value == "*" || value == "/";
            if (value_is_sign)
            {
                if (ops_values.empty())
                    break;

                // Cannot have more than 2 numbers before sign
                if (ops_values.size() > 2)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }

                // Initialize sum
                if (is_first_run)
                {
                    sum = ops_values.front();
                    ops_values.pop();
                    is_first_run = false;
                }

                if (value == "+")
                    sum += ops_values.front();
                else if (value == "-")
                    sum -= ops_values.front();
                else if (value == "*")
                    sum *= ops_values.front();
                else if (value == "/")
                    sum /= ops_values.front();

                std::cout << "sum is: ." << sum << "." << std::endl;

                ops_values.pop();
                break;
            }
            else
                ops_values.push(stoi(value));

            // Remove parse value
            current_ops = current_ops.substr(end);
        }
        this->_ops.pop();
    }
    std::cout << sum;
}