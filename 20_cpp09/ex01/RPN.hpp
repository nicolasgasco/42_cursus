#pragma once
#ifndef __RPN_H__
#define __RPN_H__

#include <iostream>
#include <queue>

class RPN
{

public:
    RPN();
    // RPN(RPN const &src);

    ~RPN();

    void calculate(std::string const &input);

private:
    std::queue<std::string> _ops;
    bool _has_err;

    void _parse_input(std::string const &input);
};

#endif