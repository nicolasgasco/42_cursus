#include "../../utils.hpp"
#include "../stack.hpp"

void ownStackDefaultConstructor()
{
    ft::stack<int> myStack;
}
void seedStackDefaultConstructor()
{
    std::stack<int> myStack;
}

void ownStackContainerConstructor()
{
    ft::vector<int> ref(100, 3);
    std::stack<int, ft::vector<int> > myStack(ref);
}
void seedStackContainerConstructor()
{
    std::vector<int> ref(100, 3);
    std::stack<int, std::vector<int> > myStack(ref);
}

void ownStackAssignOperator()
{
    ft::stack<std::string> ownRef;
    ownRef.push("foo");
    ownRef.push("bar");
    ft::stack<std::string> ownStack;
    ownStack = ownRef;

    std::stack<std::string> originalRef;
    originalRef.push("foo");
    originalRef.push("bar");
    std::stack<std::string> originalStack;
    originalStack = originalRef;
}
void seedStackAssignOperator()
{
    ft::stack<std::string> ownRef;
    ownRef.push("foo");
    ownRef.push("bar");
    ft::stack<std::string> ownStack;
    ownStack = ownRef;

    std::stack<std::string> originalRef;
    originalRef.push("foo");
    originalRef.push("bar");
    std::stack<std::string> originalStack;
    originalStack = originalRef;
}

void constructorsStackSpeedTest(bool isDebug)
{
    std::cout << "  CONSTRUCTORS:" << std::endl;
    {
        std::cout << "  - Default constructor without container:";
        calculateSpeedRatio(ownStackDefaultConstructor, seedStackDefaultConstructor, isDebug);
    }
    {
        std::cout << "  - Default constructor with container:";
        calculateSpeedRatio(ownStackContainerConstructor, seedStackContainerConstructor, isDebug);
    }
    {
        std::cout << "  - Assign operator:";
        calculateSpeedRatio(ownStackAssignOperator, seedStackAssignOperator, isDebug);
    }
}
