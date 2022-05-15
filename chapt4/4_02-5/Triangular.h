#pragma one
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
class Triangular
{
private:
    int _length;
    int _beg_pos;
    mutable int _next;
    static std::vector<int> _elemts;
    static const int _max_size = 1024;
public:
    Triangular(int len = 1, int beg = 1);
    Triangular(Triangular &rhs) : _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1) {}
    ~Triangular();
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;
    bool next(int &val) const;
    void next_reset() const { _next = _beg_pos - 1 ;}

    Triangular& copy(const Triangular&);
    static bool is_elem(int);
    static void gen_elemts(int);
    static void gen_elems_to_value(int);
    static void display(int length, int beg, std::ostream& os = std::cout);
};