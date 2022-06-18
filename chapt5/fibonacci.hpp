#include "num_sequence.hpp"

class Fibonacci : public num_sequence
{   
public:
    Fibonacci(int length = 1, int beg_pos = 1) : num_sequence(length, beg_pos, _elems) { }
    // virtual const char* what_am_i() const { return "Fibonacci"; }
protected:
    virtual void gen_elems(int pos) const;
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