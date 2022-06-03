#pragma one
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
class Triangular_iterator
{
private:
    void check_integrity() const;
    int _index;
public:
    Triangular_iterator(int index) : _index(index - 1) {}
    bool operator==(const Triangular_iterator&) const;
    bool operator!=(const Triangular_iterator&) const;
    int operator*() const;
    Triangular_iterator& operator++();
    Triangular_iterator& operator++(int);
};

class Triangular
{
    friend class Triangular_iterator;
private:
    int _length;
    int _beg_pos;
    mutable int _next;
    static std::vector<int> _elemts;
    static const int _max_size = 1024;
public:
    typedef Triangular_iterator iterator;
    Triangular_iterator begin() const
    {
        return Triangular_iterator(_beg_pos);
    }
    Triangular_iterator end() const
    {
        return Triangular_iterator(_beg_pos + _length);
    }

    Triangular(int len = 1, int beg = 1);
    Triangular(Triangular &rhs) : _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1) {}
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;
    bool next(int &val) const;
    void next_reset() const { _next = _beg_pos - 1 ;}
    friend std::ostream& operator<<(std::ostream &os, const Triangular& rhs);
    friend std::istream& operator>>(std::istream &is, Triangular& rhs);
    Triangular& copy(const Triangular&);
    static bool is_elem(int);
    static void gen_elemts(int);
    static void gen_elems_to_value(int);
    static void display(int length, int beg, std::ostream& os = std::cout);
};


// Triangular——iterator类的实现
inline  bool Triangular_iterator::
operator==(const Triangular_iterator& rhs) const
{ return _index == rhs._index; }

inline  bool Triangular_iterator::
operator!=(const Triangular_iterator& rhs) const
{ return !(*this == rhs); }

inline int Triangular_iterator::
operator*() const
{ 
    check_integrity();
    return Triangular::_elemts[_index];
}

inline void Triangular_iterator::
check_integrity() const
{
    if(_index >= Triangular::_max_size)
        // throw iterator_overflow();       // 抛出异常
    if(_index >= Triangular::_elemts.size())
        Triangular::gen_elemts(_index + 1);
}

inline Triangular_iterator& Triangular_iterator::
operator++()
{
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator& Triangular_iterator::
operator++( int )
{
    Triangular_iterator& tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}


// Triangular类的实现
std::vector<int> Triangular::_elemts;

Triangular::Triangular(int len, int beg)
: _length(len>0 ? len : 1), _beg_pos(beg>0 ? beg : 1)
{
    _next = beg - 1;
    int elem_cnt = _beg_pos + _length - 1;
    if(_elemts.size() < elem_cnt)
        gen_elemts(elem_cnt);
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
        os << _elemts[i]  << " ";
}

std::ostream& operator<<(std::ostream &os, const Triangular& rhs)
{
    os << "( " << rhs.beg_pos() << " " << rhs.length() << " )";
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

std::istream& operator>>(std::istream &is, Triangular& rhs)
{
    int bp, len;
    is >> bp >> len;
    rhs._length = len;
    rhs._beg_pos = bp;
    rhs.next_reset();
    return is;
}