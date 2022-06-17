#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence();
    virtual int elem(int pos) = 0;
    virtual const char* what_am_i() const = 0;
    virtual ostream& print(ostream& os = cout) const = 0;
    static int max_elems() { return _max_elems; }
protected:
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;
    const static int _max_elems = 1024;
};

inline num_sequence::~num_sequence() {}

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

ostream& operator << (ostream& os, num_sequence& ns)
{
    return ns.print(os);
}