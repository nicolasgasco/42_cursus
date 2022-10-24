#include "span.hpp"

Span::Span(unsigned int N) : size(N)
{
    std::cout << PURPLE << "Span parameter constructor called (" << N << ")" << NOCOL << std::endl;
    this->ints.reserve(N);
}

Span::Span(Span const &src) : size(src.size)
{
    std::cout << PURPLE << "Span copy constructor called" << NOCOL << std::endl;
    *this = src;
}

Span::~Span(void)
{
    std::cout << PURPLE << "Span destructor called" << NOCOL << std::endl;
}

Span &Span::operator=(const Span &src)
{
    std::cout << PURPLE << "Span assignment operator" << NOCOL << std::endl;
    this->ints.reserve(src.ints.size());
    for (unsigned int i = 0; i < src.ints.size(); ++i)
    {
        this->ints.push_back(src.ints[i]);
    }
    return *this;
}

void Span::addNumber(int value)
{
    if (ints.size() == size)
        throw("List is already full");
    ints.push_back(value);
}

void absoluteValue(int &n)
{
    n = abs(n);
}

unsigned int Span::shortestSpan(void)
{

    if (this->ints.size() <= 1)
        throw("There is no Span to find");

    std::vector<int>::const_iterator start = this->ints.begin();
    std::vector<int>::const_iterator end = this->ints.end();

    std::vector<int> differences(this->size);
    std::vector<int>::iterator differencesStart = differences.begin();

    std::adjacent_difference(start, end, differencesStart);

    std::for_each(
        differences.begin(), differences.end(), absoluteValue);

    int minValue = *(std::min_element(differences.begin(), differences.end()));

    return (minValue);
}

unsigned int Span::longestSpan(void) const
{
    if (this->ints.size() <= 1)
        throw("There is no Span to find");

    std::vector<int>::const_iterator start = this->ints.begin();
    std::vector<int>::const_iterator end = this->ints.end();

    std::vector<int> differences(this->size);
    std::vector<int>::iterator differencesStart = differences.begin();

    std::adjacent_difference(start, end, differencesStart);

    std::for_each(
        differences.begin(), differences.end(), absoluteValue);

    int maxValue = *(std::max_element(differences.begin(), differences.end()));
    return (maxValue);
}

int generateRandInt(void)
{
    return (rand() % 5000 + 1);
}

void Span::addRandomNumbers(void)
{
    std::cout << PURPLE << "Filling up vector with random numbers" << NOCOL << std::endl;

    srand(time(NULL));

    std::vector<int> temp(this->size);
    std::generate(temp.begin(), temp.end(), generateRandInt);

    this->ints = temp;
}

Span::Span(void) : size(0)
{
    std::cout << PURPLE << "Span default constructor called" << NOCOL << std::endl;
}

void Span::outputVector(void) const
{
    if (this->ints.size() == 0)
    {
        std::cout << "Empty vector" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < this->ints.size(); ++i)
    {
        if (i < 100)
            std::cout << PURPLE << this->ints[i] << ", " << NOCOL;
    }
    if (this->ints.size() > 100)
        std::cout << PURPLE << " * * * values omitted for brevity * * *" << NOCOL << std::endl;
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, Span const &std)
{
    std.outputVector();
    return os;
}