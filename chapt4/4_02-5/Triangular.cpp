#include "Triangular.h"
#include <iostream>

std::vector<int> Triangular::_elemts;

Triangular::Triangular(int len, int beg)
: _length(len>0 ? len : 1), _beg_pos(beg>0 ? beg : 1)
{
    _next = beg - 1;
    int elem_cnt = _beg_pos + _length - 1;
    if(_elemts.size() < elem_cnt)
        gen_elemts(elem_cnt);               // 未实现
}
int Triangular::elem(int pos) const
{
    return _elemts[pos - 1];
}

bool Triangular::next(int &val) const
{
    if(_next < _beg_pos + _length - 1)
    {
        val = _elemts[_next++];
        return true;
    }
    return false;
}

Triangular& Triangular::copy(const Triangular& tria)
{
    if(this != &tria)
    {
        _length = tria._length;
        _beg_pos = tria._beg_pos;
        _next = tria._beg_pos - 1;
    }
    return *this;
}

bool Triangular::is_elem(int val)
{
    if(!_elemts.size() || _elemts.back() < val)
        gen_elems_to_value(val);
    std::vector<int>::iterator found_it;
    std::vector<int>::iterator end = _elemts.end();
    found_it = std::find(_elemts.begin(), end, val);
    return (found_it != end);
}

void Triangular::gen_elems_to_value(int val)
{
    int size = _elemts.size();
    if(!size)
    {
        _elemts.push_back(1);
        size = 1;
    }
    while(_elemts.back() < val && size < _max_size)
    {
        ++size;
        _elemts.push_back(size*(size + 1)/2);
    }
    if(size == _elemts.max_size())
    {
        std::cerr << val << " -- exceeds max size of " << _max_size << std::endl;
    }
}

void Triangular::gen_elemts(int length)
{
    if(length < 0 || length > _max_size)
        return;
    if(_elemts.size() < length)
    {
        int i = _elemts.size() + 1;
        for(; i <= length; i++)
        {
            _elemts.push_back(i*(i+1)/2);
        }
    }
}

void Triangular::display(int length, int beg, std::ostream& os)
{
    int size = beg + length - 1;
    for(int i = beg - 1; i < size; ++i)
        os << _elemts[i];
}