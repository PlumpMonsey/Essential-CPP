#include "Stack.h"

inline bool Stack::full()
{
    return _stack.size() == _stack.max_size();
}

inline bool Stack::empty()
{
    return _stack.empty();
}

bool Stack::push(const std::string& s)
{
    if(full())
        return false;
    _stack.push_back(s);
    return true;
}

bool Stack::pop(std::string& s)
{
    if(empty())
        return false;
    s = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(std::string& s)
{
    if(empty())
        return false;
    s = _stack.back();
    return true;
}