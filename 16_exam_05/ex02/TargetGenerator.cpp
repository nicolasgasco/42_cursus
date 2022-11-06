#include "TargetGenerator.hpp"
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

TargetGenerator::TargetGenerator(void)
{
    std::cout << "Creating new TargetGenerator" << std::endl;
}

TargetGenerator::~TargetGenerator(void)
{
    std::list<ATarget *>::iterator start = this->targets.begin();
    std::list<ATarget *>::iterator end = this->targets.end();
    for (; start != end; ++start)
        delete *start;
    this->targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    std::list<ATarget *>::iterator start = this->targets.begin();
    std::list<ATarget *>::iterator end = this->targets.end();
    for (; start != end; ++start)
    {
        if ((*start)->getType() == target->getType())
        {
            std::cout << "Target type already learnt" << std::endl;
            return;
        }
    }
    this->targets.push_back(target->clone());
    std::cout << "Learnt target type " << target->getType() << std::endl;
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
    std::list<ATarget *>::iterator start = this->targets.begin();
    std::list<ATarget *>::iterator end = this->targets.end();
    for (; start != end; ++start)
    {
        if ((*start)->getType() == targetType)
        {
            std::cout << "Target deleted: " << targetType << std::endl;
            delete *start;
            this->targets.erase(start);
        }
    }
    std::cout << "No target to forget" << std::endl;
}

ATarget *TargetGenerator::createTarget(std::string const &targetType)
{
    std::list<ATarget *>::iterator start = this->targets.begin();
    std::list<ATarget *>::iterator end = this->targets.end();
    for (; start != end; ++start)
    {
        if ((*start)->getType() == targetType)
        {
            std::cout << "Generated new spell: " << targetType << std::endl;
            return (*start);
        }
    }
    return (nullptr);
}
