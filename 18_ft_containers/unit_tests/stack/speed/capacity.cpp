#include "../../utils.hpp"
#include "../stack.hpp"

void ownStackSize()
{
    ft::vector<char> ref(100000, 10);
    ft::stack<char, ft::vector<char> > myStack(ref);
    myStack.size();
}
void seedStackSize()
{
    std::vector<char> ref(100000, 10);
    std::stack<char, std::vector<char> > myStack(ref);
    myStack.size();
}

void ownStackEmpty()
{
    ft::vector<char> ref(100000, 10);
    ft::stack<char, ft::vector<char> > myStack(ref);
    myStack.empty();
}
void seedStackEmpty()
{
    std::vector<char> ref(100000, 10);
    std::stack<char, std::vector<char> > myStack(ref);
    myStack.empty();
}

void capacityStackSpeedTest(bool isDebug)
{
    std::cout << std::endl
              << "  CAPACITY:" << std::endl;
    {
        std::cout << "  - size of stack with 100000 elements:";
        calculateSpeedRatio(ownStackSize, seedStackSize, isDebug);
    }
    {
        std::cout << "  - empty of stack with 100000 elements:";
        calculateSpeedRatio(ownStackEmpty, seedStackEmpty, isDebug);
    }
}
