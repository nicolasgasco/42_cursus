#include <stack>
#include <deque>
#include <list>

#include "utils.hpp"
#include "../stack.hpp"

void reletionalOperatorStackUnitTests(bool isDebug)
{
    outputSuiteTitle("RELETIONAL OPERATORS:");
    {
        {
            std::cout << std::endl
                      << "EQUAL:" << std::endl;
            {
                ft::stack<int> ownStack;
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                std::stack<int> originalRef;

                outputAssertion("with default constructor", isStrictEqual<bool>(ownStack == ownRef, originalStack == originalRef, isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ft::stack<int> ownRef;
                ownRef.push(42);

                std::stack<int> originalStack;
                originalStack.push(42);
                std::stack<int> originalRef;
                originalRef.push(42);

                outputAssertion("after 1 pop", isStrictEqual<bool>(ownStack == ownRef, originalStack == originalRef, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "NOT EQUAL:" << std::endl;
            {
                ft::stack<int> ownStack;
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                std::stack<int> originalRef;

                outputAssertion("with default constructor", isStrictEqual<bool>(ownStack != ownRef, originalStack != originalRef, isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                originalStack.push(42);
                std::stack<int> originalRef;

                outputAssertion("after 1 pop", isStrictEqual<bool>(ownStack != ownRef, originalStack != originalRef, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "LESS EQUAL THAN:" << std::endl;
            {
                ft::stack<int> ownStack;
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                std::stack<int> originalRef;

                outputAssertion("with default constructor", isStrictEqual<bool>(ownStack <= ownRef, originalStack <= originalRef, isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                originalStack.push(42);
                std::stack<int> originalRef;

                outputAssertion("after 1 pop", isStrictEqual<bool>(ownStack <= ownRef, originalStack <= originalRef, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "GREATER THAN:" << std::endl;
            {
                ft::stack<int> ownStack;
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                std::stack<int> originalRef;

                outputAssertion("with default constructor", isStrictEqual<bool>(ownStack > ownRef, originalStack > originalRef, isDebug));
            }
            {
                ft::stack<int> ownStack;
                ownStack.push(42);
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                originalStack.push(42);
                std::stack<int> originalRef;

                outputAssertion("after 1 pop", isStrictEqual<bool>(ownStack > ownRef, originalStack > originalRef, isDebug));
            }
        }
        {
            std::cout << std::endl
                      << "GREATER EQUAL THAN:" << std::endl;
            {
                ft::stack<int> ownStack;
                ft::stack<int> ownRef;

                std::stack<int> originalStack;
                std::stack<int> originalRef;

                outputAssertion("with default constructor", isStrictEqual<bool>(ownStack >= ownRef, originalStack >= originalRef, isDebug));
            }
            {
                ft::stack<int> ownStack;
                ft::stack<int> ownRef;
                ownRef.push(42);

                std::stack<int> originalStack;
                std::stack<int> originalRef;
                originalRef.push(42);

                outputAssertion("after 1 pop", isStrictEqual<bool>(ownStack >= ownRef, originalStack >= originalRef, isDebug));
            }
        }
    }
}