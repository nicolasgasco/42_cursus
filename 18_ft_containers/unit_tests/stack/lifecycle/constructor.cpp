#include <stack>
#include <list>
#include <vector>

#include "../../utils.hpp"
#include "../../../stack.hpp"

void constructorUnitTests(bool isDebug)
{
    outputSuiteTitle("CONSTRUCTOR:");
    {
        std::cout
            << "Stacks are equal:" << std::endl;
        {
            ft::stack<int> ownStack;

            std::stack<int> originalStack;

            outputAssertion("when initializing with empty constructor", areStacksStrictEqual(ownStack, originalStack, isDebug));
        }
        {
            ft::vector<int> ref(10, 3);

            ft::stack<int, ft::vector<int> > ownStack(ref);

            std::stack<int, ft::vector<int> > originalStack(ref);

            outputAssertion("when initializing with argument ft::vector", areStacksStrictEqual(ownStack, originalStack, isDebug));
        }
        {
            std::vector<int> ref(10, 3);

            ft::stack<int, std::vector<int> > ownStack(ref);

            std::stack<int, std::vector<int> > originalStack(ref);

            outputAssertion("when initializing with argument std::vector", areStacksStrictEqual(ownStack, originalStack, isDebug));
        }
        {
            std::deque<std::string> ref(3, "foo");

            ft::stack<std::string, std::deque<std::string> > ownStack(ref);

            std::stack<std::string, std::deque<std::string> > originalStack(ref);

            outputAssertion("when initializing with argument std::deque", areStacksStrictEqual(ownStack, originalStack, isDebug));
        }
        {
            std::list<int> ref(3, 42);

            ft::stack<int, std::list<int> > ownStack(ref);

            std::stack<int, std::list<int> > originalStack(ref);

            outputAssertion("when initializing with argument std::list", areStacksStrictEqual(ownStack, originalStack, isDebug));
        }
    }
}