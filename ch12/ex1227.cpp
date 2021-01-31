#include "ex1227.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

TextQuery::TextQuery(std::ifstream& infile): vptr()
{
    for (std::string text; std::getline(infile, text); )
    {
        vptr.push_back(text);
        lineNo n = vptr.size() - 1;
        
        std::istringstream ss(text);
        std::string str;
        while (ss >> str)
        {
            std::string word;
            std::remove_copy_if(str.begin(), str.end(), std::back_inserter(word), ispunct);
            auto &lines = mp[word];
            if (!lines) lines = std::make_shared<std::set<TextQuery::lineNo>>();  
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &s) const
{
    static std::shared_ptr<std::set<TextQuery::lineNo>> nodata(std::make_shared<std::set<lineNo>>());
    
    auto seek = mp.find(s);
    if (seek == mp.end())
        return QueryResult(s, vptr, nodata);
    else 
        return QueryResult(s, vptr, seek->second);
}

std::ostream& print(std::ostream &os, const QueryResult &res)
{
    auto times = (res.lines)->size();
    os << res.sought << " occurs " << times << ( times > 1 ? " times" : " time") << std::endl; 

    for (auto it = res.begin(); it != res.end(); ++ it)
    {
        const StrBlobPtr p(*res.get_file(), *it);
        os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
    }
    return os;
}

