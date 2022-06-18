#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence();
    int elem(int pos);
    // virtual const char* what_am_i() const;
    const char* what_am_i() const;
    ostream& print(ostream& os = cout) const;
    static int max_elems() { return _max_elems; }

    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
protected:
    num_sequence(int length, int beg_pos, vector<int>& re) : 
                _length(length), _beg_pos(beg_pos), _relems(re) { }
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

    int _length;
    int _beg_pos;
    const static int _max_elems = 1024;
    vector<int>& _relems;
};

inline num_sequence::~num_sequence() {}

const char* num_sequence::what_am_i() const
{
    return typeid(*this).name();
}

inline bool num_sequence::
check_integrity(int pos, int size) const
{
    if(pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                  <<"-- cannot handle request!\n";
        return false;
    }
    if(pos > size)
        gen_elems(pos);
    return true;
}

int num_sequence::
elem(int pos)
{
    if(!check_integrity(pos, _relems.size()))
        return 0;
    return _relems[pos - 1];
}

ostream& num_sequence::
print(ostream& os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    if(!check_integrity(end_pos, _relems.size()))
        return os;
    while(elem_pos < end_pos)
    {
        os << _relems[elem_pos++] << ' ';
    }
    return os;
}

ostream& operator << (ostream& os, num_sequence& ns)
{
    return ns.print(os);
}