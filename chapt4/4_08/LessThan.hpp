#pragma one

class LessThan
{
private:
    int _val;
public:
    LessThan(int val) : _val(val) {}
    int comp_val() const { return _val; }
    void comp_val(int nval) { _val = nval; }
    bool operator() (int val) const;
};

inline bool LessThan::
operator() (int val) const
{
    return _val < val;
}