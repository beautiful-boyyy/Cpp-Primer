#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec {1, 1, 2, 2, 2, 3, 3, 4, 7, 7, 9, 9, 9, 10};
    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int const &a) -> void { cout << a << " "; });
    cout << endl;
    cout << lower_bound(vec.begin(), vec.end(), 2) - vec.begin() << endl;
    cout << upper_bound(vec.begin(), vec.end(), 2) - vec.begin() << endl;
    return 0;
}
