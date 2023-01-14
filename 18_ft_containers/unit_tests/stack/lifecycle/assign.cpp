#include <stack>
#include <deque>
#include <list>

#include "../../utils.hpp"
#include "../../../stack.hpp"

void assignStackUnitTests(bool isDebug)
{
    outputSuiteTitle("ASSIGN");
    {
        std::cout
            << "Stacks are equal:" << std::endl;
        {
            std::cout << "  - NOT CONST" << std::endl;
            {
                ft::stack<int> ownRef;
                ownRef.push(42);
                ownRef.push(1);
                ownRef.push(100);
                ft::stack<int> ownStack;
                ownStack = ownRef;

                std::stack<int> originalRef;
                originalRef.push(42);
                originalRef.push(1);
                originalRef.push(100);
                std::stack<int> originalStack;
                originalStack = originalRef;

                outputAssertion("when assigning to another stack<int>", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
            }
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

                outputAssertion("when assigning to another stack<std::string>", areStacksStrictEqual<std::string>(ownStack, originalStack, isDebug));
            }
        }
        {
            std::cout << "  - CONST" << std::endl;
            {
                ft::stack<int> ownRef;
                ownRef.push(42);
                ownRef.push(1);
                ownRef.push(100);
                ft::stack<int> ownStack;
                ownStack = const_cast<ft::stack<int> &>(ownRef);

                std::stack<int> originalRef;
                originalRef.push(42);
                originalRef.push(1);
                originalRef.push(100);
                std::stack<int> originalStack;
                originalStack = const_cast<std::stack<int> &>(originalRef);

                outputAssertion("when assigning to another stack<int>", areStacksStrictEqual<int>(ownStack, originalStack, isDebug));
            }
            {
                ft::stack<std::string> ownRef;
                ownRef.push("foo");
                ownRef.push("bar");
                ft::stack<std::string> ownStack;
                ownStack = static_cast<ft::stack<std::string> &>(ownRef);

                std::stack<std::string> originalRef;
                originalRef.push("foo");
                originalRef.push("bar");
                std::stack<std::string> originalStack;
                originalStack = const_cast<std::stack<std::string> &>(originalRef);

                outputAssertion("when assigning to another stack<std::string>", areStacksStrictEqual<std::string>(ownStack, originalStack, isDebug));
            }
        }
    }
}