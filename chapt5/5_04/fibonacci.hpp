#include "num_sequence.hpp"

class Fibonacci : public num_sequence
{   
public:
    Fibonacci(int length = 1, int beg_pos = 1) : 
            _length(length), _beg_pos(beg_pos) { };
    virtual int elem(int pos);
    virtual const char* what_am_i() const { return "Fibonacci"; }
    virtual ostream& print(ostream& os = cout) const;

    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
protected:
    virtual void gen_elems(int pos) const;
    int _length;
    int _beg_pos;
    static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

void Fibonacci::
gen_elems(int pos) const
{
    for(int i = _elems.size(); i < pos; ++i)
    {
        if(i <= 1)
            _elems.push_back(1);
        else
            _elems.push_back(_elems[i - 1] + _elems[i - 2]);
    }
}

ostream& Fibonacci::
print(ostream& os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    if(!num_sequence::check_integrity(end_pos, _elems.size()))
        return os;
    while(elem_pos < end_pos)
    {
        os << _elems[elem_pos++] << ' ';
    }
    return os;
}

int Fibonacci::
elem(int pos)
{
    if(!num_sequence::check_integrity(pos, _elems.size()))
        return 0;

    return _elems[pos - 1];
}