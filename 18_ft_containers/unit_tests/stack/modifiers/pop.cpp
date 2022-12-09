#include <stack>
#include <deque>
#include <list>

#include "utils.hpp"
#include "../stack.hpp"

void popStackUnitTests(bool isDebug)
{
    outputSuiteTitle("PUSH:");
    {
        std::cout
            << "Container is equal:" << std::endl;

        {
            ft::stack<int> ownStack;
            ownStack.push(42);
            ownStack.pop();

            std::stack<int> originalStack;
            originalStack.push(42);
            originalStack.pop();

            outputAssertion("after 1 pop", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
        {
            ft::stack<int> ownStack;
            ownStack.push(42);
            ownStack.push(42);
            ownStack.pop();
            ownStack.pop();

            std::stack<int> originalStack;
            originalStack.push(42);
            originalStack.push(42);
            originalStack.pop();
            originalStack.pop();

            outputAssertion("after 2 pop", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
        {
            ft::stack<int> ownStack;
            ownStack.push(42);
            ownStack.push(42);
            ownStack.push(42);
            ownStack.pop();
            ownStack.pop();
            ownStack.pop();

            std::stack<int> originalStack;
            originalStack.push(42);
            originalStack.push(42);
            originalStack.push(42);
            originalStack.pop();
            originalStack.pop();
            originalStack.pop();

            outputAssertion("after 3 pop", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
        {
            ft::stack<int> ownStack;
            for (int i = 0; i < 50; ++i)
                ownStack.push(i);
            for (int i = 0; i < 50; ++i)
                ownStack.pop();

            std::stack<int> originalStack;
            for (int i = 0; i < 50; ++i)
                originalStack.push(i);
            for (int i = 0; i < 50; ++i)
                originalStack.pop();

            outputAssertion("after 50 pop", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
        }
    }
}