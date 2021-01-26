#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char **argv)
{
    cout << argc << endl;    
    for (int i = 0; i < argc; ++ i)
        cout << argv[i] << " ";
    cout << endl;
    return 0;
}
