
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *a, unsigned int len, void func(T const &))
{
    for (unsigned int i = 0; i < len; i++)
    {
        func(a[i]);
    }
}

template <typename T>
void outputArrayValue(T value)
{
    std::cout << "- " << value << std::endl;
}

// This is not part of the subject-required code
// It's there to test code with complex types
class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }

private:
    int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
    o << rhs.get();
    return o;
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
    return;
}

#endif
