#pragma once
#ifndef __KAREN_H__
#define __KAREN_H__

#include <iostream>

class Karen;

typedef struct MethodPointer
{
    std::string id;
    void (Karen::*func_ptr)(void) const;
} mtd_ptr;
class Karen
{

public:
    Karen(void);
    ~Karen(void);

    void complain(std::string level);

private:
    mtd_ptr ptr_arr[4];

    void debug(void) const;
    void info(void) const;
    void warning(void) const;
    void error(void) const;
};

#endif