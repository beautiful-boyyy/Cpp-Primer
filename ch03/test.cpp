#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string str = "";
    for (string buffer; cin >> buffer; str += (str.empty() ? "" : " ") + buffer);
    cout << str << endl;
    return 0;
}
