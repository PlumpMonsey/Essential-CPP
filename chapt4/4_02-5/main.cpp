#include "Triangular.h"
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
    char ch;
    bool more = true;
    while(more)
    {
        int val;
        cout << "Enter a value: ";
        cin >> val;
        bool is_elem = Triangular::is_elem(val);
        cout << val
             << (is_elem?" is ":" is not ")
             << "an element in the Triangular series.\n"
             << "Another value?(y/n) ";
        cin >> ch;
        if(ch == 'n' || ch == 'N')
            more = false;
    }
}