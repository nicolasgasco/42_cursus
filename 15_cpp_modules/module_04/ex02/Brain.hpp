#pragma once
#ifndef __BRAIN_H__
#define __BRAIN_H__
#define GREEN "\033[0;32m"
#define NOCOL "\033[0m"
#include <iostream>

class Brain
{
public:
    Brain(void);
    Brain(Brain const &src);

    virtual ~Brain(void);

    Brain &operator=(Brain const &src);

private:
    static int const ideasNum = 100;
    std::string ideas[ideasNum];
};

#endif