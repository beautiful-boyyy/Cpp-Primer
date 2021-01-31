#ifndef EX1227_H
#define EX1227_H

#include <fstream>
#include <map>
#include <ostream>
#include <set>
#include <memory>
#include <string>
#include <vector>

#include "ex1219.h"

class QueryResult;

class TextQuery
{
public:
    using lineNo = sz;
private:
    StrBlob vptr;
    std::map<std::string, std::shared_ptr<std::set<lineNo>>> mp;

public:
    TextQuery(std::ifstream& infile);
    QueryResult query(std::string const &s) const;
};

class QueryResult
{
public:
    using ResultIter = std::set<sz>::iterator;
    friend std::ostream& print(std::ostream&, const QueryResult&);
private:
    std::string sought;
    StrBlob qptr;
    std::shared_ptr<std::set<TextQuery::lineNo>> lines;

public:
    QueryResult(std::string const &s, StrBlob const &q, std::shared_ptr<std::set<TextQuery::lineNo>> p):
        sought(s), qptr(q), lines(p) { }
    ResultIter begin() const
    {
        return lines->begin();
    }
    
    ResultIter end() const
    {
        return lines->end();
    }
    
    std::shared_ptr<StrBlob> get_file() const
    {
        return std::make_shared<StrBlob>(qptr);
    }
};

#endif /* EX1227_H */
