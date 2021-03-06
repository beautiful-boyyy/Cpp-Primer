#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector; 
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (std::getline(ifs, buf))
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    ReadFileToVec("../data/book.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}

