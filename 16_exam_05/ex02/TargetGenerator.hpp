#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <iostream>
#include <list>

class ATarget;

class TargetGenerator
{
public:
    TargetGenerator(void);
    virtual ~TargetGenerator(void);

    void learnTargetType(ATarget *);
    void forgetTargetType(std::string const &);
    ATarget *createTarget(std::string const &);

protected:
    std::list<ATarget *> targets;

    TargetGenerator(TargetGenerator const &src);
    TargetGenerator const &operator=(TargetGenerator const &src);
};

#endif