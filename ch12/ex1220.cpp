#include "ex1219.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifs("../data/book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
    return 0;
}
