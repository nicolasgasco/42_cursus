#include <stack>
#include <deque>
#include <list>

#include "../../utils.hpp"
#include "../../../stack.hpp"

void topStackUnitTests(bool isDebug)
{
    outputSuiteTitle("TOP");
    {
        std::cout
            << "Return value is equal:" << std::endl;
        {
            std::cout << "  - NOT CONST" << std::endl;
            {
                ft::stack<int> ownStack;
                ownStack.push(42);

                std::stack<int> originalStack;
                originalStack.push(42);

                outputAssertion("with stack<int> of size 1", isStrictEqual<int>(ownStack.top(), originalStack.top(), isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ownStack.push(1);

                std::stack<int> originalStack;
                originalStack.push(42);
                originalStack.push(1);

                outputAssertion("with stack<int> of size 2", isStrictEqual<int>(ownStack.top(), originalStack.top(), isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ownStack.push(1);
                ownStack.push(100);

                std::stack<int> originalStack;
                originalStack.push(42);
                originalStack.push(1);
                originalStack.push(100);

                outputAssertion("with stack<int> of size 3", isStrictEqual<int>(ownStack.top(), originalStack.top(), isDebug));
            }
            {
                ft::stack<std::string> ownStack;
                ownStack.push("foo");

                std::stack<std::string> originalStack;
                originalStack.push("foo");

                outputAssertion("with stack<std::string> of size 1", isStrictEqual<std::string>(ownStack.top(), originalStack.top(), isDebug));
            }
            {
                ft::stack<std::string> ownStack;
                ownStack.push("foo");
                ownStack.push("bar");

                std::stack<std::string> originalStack;
                originalStack.push("foo");
                originalStack.push("bar");

                outputAssertion("with stack<std::string> of size 2", isStrictEqual<std::string>(ownStack.top(), originalStack.top(), isDebug));
            }
            {
                ft::stack<std::string> ownStack;
                ownStack.push("foo");
                ownStack.push("bar");
                ownStack.push("baz");

                std::stack<std::string> originalStack;
                originalStack.push("foo");
                originalStack.push("bar");
                originalStack.push("baz");

                outputAssertion("with stack<std::string> of size 3", isStrictEqual<std::string>(ownStack.top(), originalStack.top(), isDebug));
            }
        }
        {
            std::cout << std::endl << "  - CONST" << std::endl;
            {
                ft::stack<int> ownStack;
                ownStack.push(42);

                std::stack<int> originalStack;
                originalStack.push(42);

                outputAssertion("with stack<int> of size 1", isStrictEqual<int>(static_cast<ft::stack<int> const &>(ownStack).top(), static_cast<std::stack<int> const &>(originalStack).top(), isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ownStack.push(1);

                std::stack<int> originalStack;
                originalStack.push(42);
                originalStack.push(1);

                outputAssertion("with stack<int> of size 2", isStrictEqual<int>(static_cast<ft::stack<int> const &>(ownStack).top(), static_cast<std::stack<int> const &>(originalStack).top(), isDebug));
            }
        }
    }
}