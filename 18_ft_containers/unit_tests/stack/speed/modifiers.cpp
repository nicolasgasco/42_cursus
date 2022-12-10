#include "../../utils.hpp"
#include "../../../stack.hpp"

void ownStackPush()
{
    ft::stack<long> myStack;
    for (int i = 0; i < 100000; ++i)
        myStack.push(i);
}
void seedStackPush()
{
    std::stack<long> myStack;
    for (int i = 0; i < 100000; ++i)
        myStack.push(i);
}

void ownStackPop()
{
    ft::stack<char> myStack;
    for (int i = 0; i < 100000; ++i)
        myStack.push(i);
    for (int i = 0; i < 100000; ++i)
        myStack.pop();
}
void seedStackPop()
{
    std::stack<char> myStack;
    for (int i = 0; i < 100000; ++i)
        myStack.push(i);
    for (int i = 0; i < 100000; ++i)
        myStack.pop();
}

void modifiersStackSpeedTest(bool isDebug)
{
    std::cout << std::endl
              << "  MODIFIERS:" << std::endl;
    {
        std::cout << "  - push_back 100000 times:";
        calculateSpeedRatio(ownStackPush, seedStackPush, isDebug);
    }
    {
        std::cout << "  - pop_back 100000 times:";
        calculateSpeedRatio(ownStackPop, seedStackPop, isDebug);
    }
}
