
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// class Awesome
// {
// public:
//     Awesome(void) : _n(0) {}
//     Awesome(int n) : _n(n) {}
//     Awesome &operator=(Awesome &a)
//     {
//         _n = a._n;
//         return *this;
//     }
//     bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
//     bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
//     bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
//     bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
//     bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
//     bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }

// private:
//     int _n;
// };
// std::ostream &operator<<(std::ostream &o, const Awesome &a)
// {
//     o << a.get_n();
//     return o;
// }

template <typename T>
void swap(T &a, T &b)
{
    T temp;

    temp = a;

    a = b;
    b = temp;
}

template <typename T>
T min(T &a, T &b)
{
    return (a < b ? a : b);
}

template <typename T>
T max(T &a, T &b)
{
    return (a > b ? a : b);
}
#endif
