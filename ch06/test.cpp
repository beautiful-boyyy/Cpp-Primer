#include <iostream>
#include <string>

void calc(const int a)
{
    std::cout << a << std::endl;
}


int main(int argc, char **argv)
{
    int *p = nullptr, a = 0;
    std::cout << typeid(p).name() << " " << typeid(a).name() << std::endl;
    int b[] = {1, 2, 3, 5};
    for (auto x: b)
        std::cout << x << " ";
    std::cout << std::endl;
    std::string str;
    std::cout << argc << std::endl;
    for (int i = 2; i < argc; ++ i)
    {
        str += std::string(argv[i]);
    }
    std::cout << str << std::endl;
    return 0;
}
