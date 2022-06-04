#include "num_sequence.h"

typedef num_sequence::PtrType PtrType;

const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);
PtrType num_sequence::func_tbl[num_seq]
{
    0,
    &num_sequence::fibo_seq,
    &num_sequence::lucas_seq,
    &num_sequence::pell_seq,
    &num_sequence::triang_seq,
    &num_sequence::squar_seq,
    &num_sequence::pent_seq
};

inline bool num_sequence::
check_integrity(int pos)
{
    if(pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                  <<"-- cannot handle request!\n";
        return false;
    }
    return true;
}
int num_sequence::
elem(int pos)
{
    if(!check_integrity(pos))
        return 0;
    if(pos > _elem->size())
        (this->*_pmf)(pos);
    return (*_elem)[pos - 1];
}

void num_sequence::set_sequence(seq_name sn)
{
    switch (sn)
    {
    default:
        cerr << "invalid type: setting to 0\n";
    case unset:
        _pmf = 0;
        _elem = 0;
        _isa = unset;
        break;
    case Fibonacci: case Lucas: case Pell:
    case Triangular: case Squar: case Pentagonal:
        _pmf = func_tbl[sn];
        _elem = &seq[sn];
        _isa = sn;
        break;
    }
}
const string num_sequence:: 
what_am_i() const
{
    static string name[num_seq]
    {
        "NotSet",
        "Fibonacci", "Lucas", "Pell",
        "Triangular", "Squar", "Pentagonal"
    };
    return name[_isa];
}
void num_sequence::
display(ostream& os, num_sequence &ns, const int pos)
{
    os << "The elem at position "
       << pos << " for the "
       << ns.what_am_i() << " sequence is "
       << ns.elem(pos) << endl;
}

void num_sequence::fibo_seq(int pos)
{
    if(!check_integrity(pos))
        return;

    _elem = &seq[Fibonacci];
    for(int i = _elem->size(); i < pos; ++i)
    {
        if(i <= 1)
            _elem->push_back(1);
        else
            _elem->push_back((*_elem)[i - 1] + (*_elem)[i - 2]);
    }
}
void num_sequence::lucas_seq(int pos)
{
    if(!check_integrity(pos))
        return;

    _elem = &seq[Lucas];

    for(int i = _elem->size(); i < pos; ++i)
    {
        if(i == 0)
            _elem->push_back(1);
        else if(i == 1)
            _elem->push_back(3);
        else
            _elem->push_back((*_elem)[i - 1] + (*_elem)[i - 2]);
    }
}
void num_sequence::pell_seq(int pos)
{
    if(!check_integrity(pos))
        return;

    _elem = &seq[Pell];

    for(int i = _elem->size(); i < pos; ++i)
    {
        if(i == 0)
            _elem->push_back(1);
        else if(i == 1)
            _elem->push_back(2);
        else
            _elem->push_back(2 * (*_elem)[i - 1] + (*_elem)[i - 2]);
    }
}
void num_sequence::triang_seq(int pos)
{
    if(!check_integrity(pos))
        return;

    _elem = &seq[Triangular];

    for(int i = _elem->size(); i < pos; ++i)
    {
        _elem->push_back((i + 1) * (i + 2) / 2);
    }
}
void num_sequence::squar_seq(int pos)
{
    if(!check_integrity(pos))
        return;

    _elem = &seq[Squar];

    for(int i = _elem->size(); i < pos; ++i)
    {
        _elem->push_back((i + 1) * (i + 1));
    }
}
void num_sequence::pent_seq(int pos)
{
    if(!check_integrity(pos))
        return;

    _elem = &seq[Pentagonal];

    for(int i = _elem->size(); i < pos; ++i)
    {
        _elem->push_back((i + 1) * (3 * i + 2) / 2);
    }
}