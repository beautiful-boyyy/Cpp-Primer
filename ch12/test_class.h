#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include <initializer_list>
#include <iostream>

class TestClass
{
private:
     int a, b, c;
public:
    TestClass() = default;
    void print()
    {
        std::cout << "hh" << std::endl;
    }
};

#endif /* TEST_CLASS_H */
