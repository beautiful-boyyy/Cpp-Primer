#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main()
{
    string rsp;
    do 
    {
        string str1, str2;
        cin >> str1 >> str2;
        cout << (str1 < str2 ? str1 : str2)
             << " is less than the other." << "\n\n"
             << "More? Enter Yes or No: ";
        cin >> rsp;
    } while (!rsp.empty() && tolower(rsp[0]) != 'n');
    return 0;
}
