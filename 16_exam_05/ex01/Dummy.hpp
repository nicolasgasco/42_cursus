#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
    Dummy(void);
    ~Dummy(void);
    virtual Dummy *clone(void);
};
#endif