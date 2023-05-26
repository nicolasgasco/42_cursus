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

    while (tmp.size() > 0)
    {
        size_t index = tmp.size();

        std::string signs[4] = {"+", "-", "*", "/"};
        for (int i = 0; i < 4; ++i)
        {
            size_t found_index = tmp.find_first_of(signs[i]);
            if (found_index != std::string::npos)
            {
                if (found_index < index)
                    index = found_index;
            }
        }

        this->_ops.push(tmp.substr(0, index + 1));

        try
        {
            tmp = tmp.substr(index + 1);
            std::string value1 = tmp.substr(0, tmp.find_first_not_of(" "));
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

    size_t ops_len = this->_ops.size();
    int sum = 0;
    bool is_first_run = true;
    for (size_t i = 0; i < ops_len; ++i)
    {
        std::queue<int> ops_values;
        std::string current_ops = this->_ops.front();
        while (1)
        {
            int start = current_ops.find_first_not_of(" ");
            current_ops = current_ops.substr(start);
            int end = current_ops.find_first_of(" ");
            std::string value = current_ops.substr(0, end);

            if (value == "+" || value == "-" || value == "*" || value == "/")
            {
                if (ops_values.empty())
                    break;
                if (ops_values.size() > 2)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }
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
                ops_values.pop();
                break;
            }
            else
                ops_values.push(stoi(value));

            current_ops = current_ops.substr(end);
        }
        this->_ops.pop();
    }
    std::cout << sum;
}