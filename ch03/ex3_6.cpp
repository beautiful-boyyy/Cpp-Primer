//Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    const string a = "dad";
    auto b = a;
    b = "mom";
    cout << b << " " << a << endl;
    return 0;
}
