#include <stack>
#include <deque>
#include <list>

#include "../../utils.hpp"
#include "../../../stack.hpp"

void sizeStackUnitTests(bool isDebug)
{
    outputSuiteTitle("SIZE:");
    {
        std::cout
            << "Return value is equal:" << std::endl;
        {
            {
                ft::stack<int> ownStack;

                std::stack<int> originalStack;

                outputAssertion("with stack<int> of size 0", isStrictEqual<int>(ownStack.size(), originalStack.size(), isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);

                std::stack<int> originalStack;
                originalStack.push(42);

                outputAssertion("with stack<int> of size 1", isStrictEqual<int>(ownStack.size(), originalStack.size(), isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ownStack.push(42);

                std::stack<int> originalStack;
                originalStack.push(42);
                originalStack.push(42);

                outputAssertion("with stack<int> of size 2", isStrictEqual<int>(ownStack.size(), originalStack.size(), isDebug));
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

                outputAssertion("with stack<int> of size 2 + 2 pop()", isStrictEqual<int>(ownStack.size(), originalStack.size(), isDebug));
            }
        }
    }
}