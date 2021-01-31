#ifndef EX1219_H
#define EX1219_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::vector; 
using std::string;

using sz = vector<string>::size_type;

class StrBlobPtr;

class StrBlob
{
public:
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob() :data(std::make_shared<vector<string>>()) { } 
    StrBlob(std::initializer_list<string> il) :data(std::make_shared<vector<string>>(il)) { }

    sz size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }

    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
    }

    string& front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string& back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const string& front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    const string& back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(sz i, string const &msg) const 
    {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
    std::shared_ptr<vector<string>> data;
};


class StrBlobPtr
{
private:
    sz curr;
    std::weak_ptr<vector<string>> wptr;

private:
    auto check(sz i, string const& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbounded error");
        if (i >= ret->size()) throw std::out_of_range("msg");
        return ret;
    }

public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &strB, sz pos = 0): wptr(strB.data), curr(pos) { }
    StrBlobPtr(const StrBlob &strB, sz pos = 0): wptr(strB.data), curr(pos) { }

    bool operator!=(const StrBlobPtr& p) { return p.curr != this->curr; }

    StrBlobPtr& incr()
    {
        check(curr, "increment made out of range error happen!");
        ++ curr;
        return *this;
    }

    string& deref()
    {
        auto p = check(curr, "dereference pase end!");
        return (*p)[curr]; 
    }

    const string& deref() const
    {
        auto p = check(curr, "dereference pase end!");
        return (*p)[curr]; 
    }
};

#endif /* EX1219_H */
