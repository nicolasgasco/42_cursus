#pragma once
#ifndef __RPN_H__
#define __RPN_H__

#include <iostream>
#include <stack>
#include <iomanip>

class RPN
{

public:
    RPN();
    RPN(std::string const &input);

    RPN(RPN const &src);

    ~RPN();

    RPN &operator=(const RPN &src);

    void calc_result(std::string const &input);
    void output_result() const;
    void output_result(std::string const &input);

private:
    std::string _err_message;
    std::stack<float> _operands;
    std::string _operators;

    void _calc_partial_result(std::string const &token);
    void _calc_result(std::string const &input);
    bool _is_space_to_skip(std::string const &token, std::string const &tmp) const;
    bool _is_token_numeric(std::string const &token) const;
    bool _is_trailing_space(std::string const &token, std::string const &tmp) const;
    void _push_operand(std::string const &token);
    void _set_err_message(std::string const &err_message);
};

#endif