#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <vector>

class Example
{
public:
    Example();
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static std::vector<double> vec;
};


#endif /* EXAMPLE_H */
