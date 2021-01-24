#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<string, int> max_duplicated;
    int cnt = 0;
    for (string str, prestr; cin >> str; prestr = str)
    {
        if (str == prestr) ++ cnt;
        else cnt = 0;
        if (cnt > max_duplicated.second) max_duplicated = {str, cnt};
    }
    if (max_duplicated.first.empty()) cout << "There is no duplicated string.";
    else cout << "The word " << max_duplicated.first << " occurs " << max_duplicated.second + 1 << " times.";
    return 0;
}
