#pragma once
#ifndef __BRAIN_H__
#define __BRAIN_H__
#define GREEN "\033[0;32m"
#define NOCOL "\033[0m"
#include <iostream>

class Brain {
   public:
    Brain(void);
    Brain(Brain const &src);

    virtual ~Brain(void);

    Brain &operator=(Brain const &src);

    std::string getType(void) const;

   private:
    std::string type;
    std::string ideas[100];
};

#endif