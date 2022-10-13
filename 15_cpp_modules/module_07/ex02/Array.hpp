#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__
#include <iostream>

#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

template <typename T>
class Array
{
public:
    Array<T>(void) : arrSize(0)
    {
        std::cout << PURPLE << "New array (default constructor)" << NOCOL << std::endl;
        this->values = new T[0];
    }

    Array<T>(unsigned int n) : arrSize(n)
    {
        std::cout << PURPLE << "New array (parameter constructor)" << NOCOL << std::endl;
        this->values = new T[n];
        for (unsigned int i = 0; i < this->arrSize; ++i)
            this->values[i] = 0;
    }

    Array<T>(Array<T> const &src)
    {
        std::cout << PURPLE << "New array (copy constructor)" << NOCOL << std::endl;
        *this = src;
    }

    ~Array<T>(void)
    {
        std::cout << PURPLE << "Array destructor" << NOCOL << std::endl;
    }

    Array<T> &operator=(Array<T> const &src)
    {
        this->arrSize = src.arrSize;
        this->values = new T[arrSize];
        for (unsigned int i = 0; i < arrSize; i++)
            this->values[i] = src.values[i];
        return (*this);
    }

    T &operator[](int index)
    {
        if (index < 0 || index > (static_cast<int>(arrSize) - 1))
            throw Array<T>::IndexOutOfBound();
        return (this->values[index]);
    }

    unsigned int size(void) const
    {
        return arrSize;
    }

private:
    T *values;
    unsigned int arrSize;

    class IndexOutOfBound : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Index value out of bound");
        }
    };
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &std)
{
    std::cout << PURPLE << "--------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Size of array is: " << std.size() << std::endl;

    if (std.size() == 0)
        std::cout << "* empty *" << std::endl;

    for (unsigned int i = 0; i < ((std.size() < 50) ? std.size() : 50); i++)
    {
        std::cout << const_cast<Array<T> &>(std)[i] << (i == (std.size() - 1) ? "" : "  ");
    }
    if (std.size() > 50)
        std::cout << "... ... ... (results hidden for brevity) ... ... ..." << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------" << NOCOL << std::endl;
    return os;
}

#endif
