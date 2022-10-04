#include "span.hpp"

void absoluteValue(int &n)
{
    n = abs(n);
}

Span::Span(unsigned int N) : size(N)
{
    std::cout << "Span parameter constructor called (" << N << ")" << std::endl;
}

Span::Span(Span const &src) : size(src.size)
{
    std::cout << "Span copy constructor called" << std::endl;
    *this = src;
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(const Span &src)
{
    std::cout << "Span assignment operator" << std::endl;
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
        throw Span::ListAlreadyFull();
    ints.push_back(value);
}

unsigned int Span::shortestSpan(void)
{
    if (this->ints.size() <= 1)
        throw Span::NoSpanToFind();

    std::vector<int>::const_iterator start = this->ints.begin();
    std::vector<int>::const_iterator end = this->ints.end();

    std::vector<int> differences(this->size);
    std::vector<int>::iterator differencesStart = differences.begin();

    std::adjacent_difference(start, end, differencesStart);

    std::for_each(
        differences.begin(), differences.end(), absoluteValue);

    return (*(std::min_element(differences.begin(), differences.end())));
}

unsigned int Span::longestSpan(void) const
{
    if (this->ints.size() <= 1)
        throw Span::NoSpanToFind();

    std::vector<int>::const_iterator start = this->ints.begin();
    std::vector<int>::const_iterator end = this->ints.end();

    std::vector<int> differences(this->size);
    std::vector<int>::iterator differencesStart = differences.begin();

    std::adjacent_difference(start, end, differencesStart);

    std::for_each(
        differences.begin(), differences.end(), absoluteValue);

    return (*(std::max_element(differences.begin(), differences.end())));
}

void Span::addRandomNumbers(unsigned int quantity)
{
    std::cout << "Add " << quantity << " numbers in bulk" << std::endl;
    srand(time(NULL));
    for (unsigned int i = 0; i < quantity; i++)
    {
        int randInt = rand() % 5000 + 1;
        this->addNumber(randInt);
        std::cout << randInt << ", ";
    }
}

Span::Span(void) : size(0)
{
    std::cout << "Span default constructor called" << std::endl;
}

void Span::outputVector(void) const
{
    for (unsigned int i = 0; i < this->ints.size(); ++i)
    {
        std::cout << this->ints[i] << ", ";
    }
    std::cout << std::endl;
}