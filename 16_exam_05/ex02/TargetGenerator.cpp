#include "TargetGenerator.hpp"
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void) {}

void TargetGenerator::learnTargetType(ATarget *target)
{
    this->targets.push_back(target);
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
    std::list<ATarget *>::iterator start = this->targets.begin();
    std::list<ATarget *>::iterator end = this->targets.end();
    for (; start != end; ++start)
    {
        if ((*start)->getType() == targetType)
        {
            this->targets.erase(start);
        }
    }
}

ATarget *TargetGenerator::createTarget(std::string const &targetType)
{
    if (targetType == "Inconspicuous Red-brick Wall")
    {
        return (new BrickWall());
    }
    else
    {
        return (new Dummy());
    }
}
