#pragma once
#ifndef __ScalarConversion_H__
#define __ScalarConversion_H__

#include <iostream>

enum Type
{
    t_int,
    t_char,
    t_float,
    t_double,
    t_float_pseudo,
    t_double_pseudo,
    t_unknown
};

class ScalarConversion
{

public:
    ScalarConversion(void);
    ScalarConversion(std::string const &strArg);
    ScalarConversion(ScalarConversion const &src);

    ~ScalarConversion(void);

    ScalarConversion &operator=(const ScalarConversion &src);
    operator int(void);

    std::string const &getStrArg(void) const;

    Type getType(void) const;

    void outputConversions(int value) const;
    void outputConversions(char value) const;
    void outputConversions(float value) const;
    void outputConversions(double value) const;

private:
    std::string const strArg;
};

#endif