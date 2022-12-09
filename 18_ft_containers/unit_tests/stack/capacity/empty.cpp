#include <stack>
#include <deque>
#include <list>

#include "utils.hpp"
#include "../stack.hpp"

void empyStackUnitTests(bool isDebug)
{
    outputSuiteTitle("EMPTY:");
    {
        std::cout
            << "Return value is equal:" << std::endl;
        {
            {
                ft::stack<int> ownStack;
                ownStack.push(42);

                std::stack<int> originalStack;
                originalStack.push(42);

                outputAssertion("with stack<int> of size 1", isStrictEqual<bool>(ownStack.empty(), originalStack.empty(), isDebug));
            }
            {
                ft::stack<int> ownStack;

                std::stack<int> originalStack;

                outputAssertion("with stack<int> of size 2", isStrictEqual<bool>(ownStack.empty(), originalStack.empty(), isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ownStack.pop();

                std::stack<int> originalStack;
                originalStack.push(42);
                originalStack.pop();

                outputAssertion("with stack<int> of size 1 + pop()", isStrictEqual<bool>(ownStack.empty(), originalStack.empty(), isDebug));
            }
        }
    }
}