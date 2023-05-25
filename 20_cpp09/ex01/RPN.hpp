#pragma once
#ifndef __RPN_H__
#define __RPN_H__

#include <iostream>
#include <vector>

class RPN
{

public:
    RPN();
    // RPN(RPN const &src);

    ~RPN();

    int calculate(std::string const &input) const;

private:
    std::vector<std::string> _signs;
};

#endif