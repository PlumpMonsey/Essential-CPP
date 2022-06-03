#include "Triangular.hpp"
using namespace std;

int sum(Triangular& rhs)
{
    if(!rhs.length())
        return 0;
    int sum = 0, val = 0;
    rhs.next_reset();
    while(rhs.next(val))
        sum += val;
    return sum;
}

int main()
{
    Triangular tri(20);
    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();
    cout << "Triangular Series of " << tri.length() << " elements\n";
    cout << tri << endl;
    while(it != end_it)
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    Triangular tri2;
    cin >>tri2;
    cout << tri2 << endl;
}