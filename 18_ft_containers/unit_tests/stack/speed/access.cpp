#include "../../utils.hpp"
#include "../stack.hpp"

void ownStackFront()
{
    ft::stack<long> myStack;
    for (int i = 0; i < 100000; ++i)
        myStack.push(i);
    myStack.top();
}
void seedStackFront()
{
    std::stack<long> myStack;
    for (int i = 0; i < 100000; ++i)
        myStack.push(i);
    myStack.top();
}

void accessStackSpeedTest(bool isDebug)
{
    std::cout << std::endl
              << "  ACCESS:" << std::endl;
    {
        std::cout << "  - top:";
        calculateSpeedRatio(ownStackFront, seedStackFront, isDebug);
    }
}
