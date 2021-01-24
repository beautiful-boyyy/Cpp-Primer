#include <iostream>
#include <typeinfo>
using namespace std;

auto f()
{
    return 1;
}

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    c = 100;
    d = 10;
    cout << typeid(d).name() << endl; 
    cout << a << " " << b << " " << c << " " << d << endl; 
    cout << f() << endl;
    return 0;
}
