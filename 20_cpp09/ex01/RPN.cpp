#include "RPN.hpp"

RPN::RPN()
{
    this->_signs.push_back("+");
    this->_signs.push_back("-");
    this->_signs.push_back("*");
    this->_signs.push_back("/");
}

RPN::~RPN()
{
}

int RPN::calculate(std::string const &input) const
{
    std::string tmp = input;

    // int value1 = 0;
    // int value2 = 0;

    while (tmp.size() > 0)
    {
        size_t index = tmp.size();
        for (std::vector<std::string>::const_iterator it = this->_signs.begin(); it != this->_signs.end(); it++)
        {
            size_t found_index = tmp.find_first_of(*it);
            if (found_index != std::string::npos)
            {
                if (found_index < index)
                    index = found_index;
            }
        }
        std::cout << "new sentence: ." << tmp.substr(0, index + 1) << "." << std::endl;
        tmp = tmp.substr(index + 1);
        std::cout << "tmp: ." << tmp << "." << std::endl;

        std::string value1 = tmp.substr(0, tmp.find_first_not_of(" "));
    }

    if (input.empty())
        return 0;
    return 0;
}