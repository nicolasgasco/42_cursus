#pragma once
#ifndef __RPN_H__
#define __RPN_H__

#include <iostream>
#include <stack>
#include <iomanip>

class RPN
{

public:
    RPN(std::string const &input);
    ~RPN();

    void output_result() const;

private:
    std::stack<float> _operands;
    std::string _operators;
    std::string _err_message;

    void _calc_partial_result(std::string const &token);
    void _calc_total(std::string const &input);
    void _push_operand(std::string const &token);
    void _set_err_message(std::string const &err_message);
};

#endif