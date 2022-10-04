#include "mutantstack.cpp"

#include <iostream>
#include <list>

#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"

int main(void)
{
    std::cout << YELLOW << "TEST WITH MUTANT STACK:" << NOCOL << std::endl;
    MutantStack<int> mstack;
    std::cout << std::endl;

    std::cout << "TESTING EMPTY:" << std::endl;
    std::cout << "Stack is empty: " << std::boolalpha << mstack.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING PUSH:" << std::endl;
    std::cout << "Pushing 5" << std::endl;
    mstack.push(5);
    std::cout << "Pushing 17" << std::endl;
    mstack.push(17);
    std::cout << "Pushing 211" << std::endl;
    mstack.push(211);
    std::cout << "Pushing 9234" << std::endl;
    mstack.push(9234);
    std::cout << "Pushing 57" << std::endl;
    mstack.push(57);
    std::cout << "Pushing 0" << std::endl;
    mstack.push(0);
    std::cout << "Pushing 99" << std::endl;
    mstack.push(99);

    std::cout << std::endl;
    std::cout << "Stack is empty: " << std::boolalpha << mstack.empty() << std::endl;

    std::cout << std::endl;
    std::cout << "TESTING SIZE:" << std::endl;
    std::cout << "Size is: " << mstack.size() << std::endl;

    std::cout << std::endl;
    std::cout << "TESTING TOP:" << std::endl;
    std::cout << "Newest number is: " << mstack.top() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING POP:" << std::endl;
    mstack.pop();

    std::cout << "Newest number after pop is: " << mstack.top() << std::endl;
    std::cout << std::endl;

    std::cout << "Size after pop is: " << mstack.size() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING INTERATORS:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    std::cout << "Value of begin iterator is: " << *it << std::endl;
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Value of end iterator is: " << *ite << std::endl;

    std::cout << std::endl;
    std::cout << "Printing stack using iterators from begin to end: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << ", ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Printing stack using iterators from end to begin: " << std::endl;
    --it;
    while (it != mstack.begin())
    {
        std::cout << *it << ", ";
        --it;
    }
    std::cout << *it << ", ";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "NOW THE SAME BUT WITH LIST:" << NOCOL << std::endl;
    std::list<int> mlist;
    std::cout << std::endl;

    std::cout << "TESTING EMPTY:" << std::endl;
    std::cout << "List is empty: " << std::boolalpha << mlist.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING PUSH:" << std::endl;
    std::cout << "Pushing 5" << std::endl;
    mlist.push_back(5);
    std::cout << "Pushing 17" << std::endl;
    mlist.push_back(17);
    std::cout << "Pushing 211" << std::endl;
    mlist.push_back(211);
    std::cout << "Pushing 9234" << std::endl;
    mlist.push_back(9234);
    std::cout << "Pushing 57" << std::endl;
    mlist.push_back(57);
    std::cout << "Pushing 0" << std::endl;
    mlist.push_back(0);
    std::cout << "Pushing 99" << std::endl;
    mlist.push_back(99);

    std::cout << std::endl;
    std::cout << "List is empty: " << std::boolalpha << mlist.empty() << std::endl;

    std::cout << std::endl;
    std::cout << "TESTING SIZE:" << std::endl;
    std::cout << "Size is: " << mlist.size() << std::endl;

    std::cout << std::endl;
    std::cout << "TESTING TOP:" << std::endl;
    std::cout << "Newest number is: " << mlist.front() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING POP:" << std::endl;
    mlist.pop_back();

    std::cout << "Newest number after pop is: " << mlist.front() << std::endl;
    std::cout << std::endl;

    std::cout << "Size after pop is: " << mlist.size() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING INTERATORS:" << std::endl;
    std::list<int>::iterator itl = mlist.begin();
    std::cout << "Value of begin iterator is: " << *itl << std::endl;
    std::list<int>::iterator itel = mlist.end();
    std::cout << "Value of end iterator is: " << *ite << std::endl;

    std::cout << std::endl;
    std::cout << "Printing stack using iterators from begin to end: " << std::endl;
    while (itl != itel)
    {
        std::cout << *itl << ", ";
        ++itl;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Printing stack using iterators from end to begin: " << std::endl;
    --itl;
    while (itl != mlist.begin())
    {
        std::cout << *itl << ", ";
        --itl;
    }
    std::cout << *itl << ", ";
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << YELLOW << "MUTANT STACK COPY CONSTRUCTOR TEST:" << NOCOL << std::endl;
    MutantStack<int> copy(mstack);

    std::cout << std::endl;
    std::cout << "Testing operators with copy:" << std::endl;
    MutantStack<int>::iterator itc = copy.begin();
    std::cout << "Value of begin iterator is: " << *itc << std::endl;
    MutantStack<int>::iterator itec = copy.end();
    std::cout << "Value of end iterator is: " << *itec << std::endl;

    std::cout << std::endl;
    std::cout << "Printing stack using iterators from begin to end: " << std::endl;
    while (itc != itec)
    {
        std::cout << *itc << ", ";
        ++itc;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return (0);
}