#include <stack>
#include <deque>
#include <list>

#include "../../utils.hpp"
#include "../../../stack.hpp"

void pushStackUnitTests(bool isDebug)
{
    outputSuiteTitle("PUSH:");
    {
        std::cout
            << "Container is equal:" << std::endl;

        {
            ft::stack<int> ownStack;
            ownStack.push(42);

            std::stack<int> originalStack;
            originalStack.push(42);

            outputAssertion("after 1 push", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
        {
            ft::stack<int> ownStack;
            ownStack.push(42);
            ownStack.push(42);

            std::stack<int> originalStack;
            originalStack.push(42);
            originalStack.push(42);

            outputAssertion("after 2 push", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
        {
            ft::stack<int> ownStack;
            ownStack.push(42);
            ownStack.push(42);
            ownStack.push(42);

            std::stack<int> originalStack;
            originalStack.push(42);
            originalStack.push(42);
            originalStack.push(42);

            outputAssertion("after 3 push", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
        {
            ft::stack<int> ownStack;
            for (int i = 0; i < 50; ++i)
                ownStack.push(i);

            std::stack<int> originalStack;
            for (int i = 0; i < 50; ++i)
                originalStack.push(i);

            outputAssertion("after 50 push", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
    }
}