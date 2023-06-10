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
    bool _is_space_to_skip(std::string const &token, std::string const &tmp) const;
    bool _is_token_numeric(std::string const &token) const;
    bool _is_trailing_space(std::string const &token, std::string const &tmp) const;
    void _push_operand(std::string const &token);
    void _set_err_message(std::string const &err_message);
};

#endif