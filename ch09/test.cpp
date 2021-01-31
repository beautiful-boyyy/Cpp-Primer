#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "nin";
    const char *ss = s.c_str();
    cout << *ss << endl;
    string str = "1233abc";
    cout << stoi(str);
    return 0;
}
