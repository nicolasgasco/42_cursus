#pragma once
#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>

class Data
{

public:
    Data(void);
    Data(int raw);
    Data(Data const &src);

    ~Data(void);

    Data &operator=(const Data &src);
    operator int(void);

    int getValue(void) const;

private:
    int value;
};

#endif