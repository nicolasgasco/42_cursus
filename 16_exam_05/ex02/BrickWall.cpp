#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall(BrickWall const &src)
{
    *this = src;
}

BrickWall::~BrickWall(void) {}

BrickWall const &BrickWall::operator=(BrickWall const &src)
{
    this->type = src.type;
    return *this;
}

ATarget *BrickWall::clone(void) const
{
    return new BrickWall();
}