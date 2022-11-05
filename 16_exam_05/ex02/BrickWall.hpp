#ifndef BrickWall_HPP
#define BrickWall_HPP

#include <iostream>

#include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
    BrickWall(void);

    virtual ATarget *clone(void) const;

    BrickWall(BrickWall const &src);
    BrickWall const &operator=(BrickWall const &src);
    ~BrickWall(void);
};

#endif