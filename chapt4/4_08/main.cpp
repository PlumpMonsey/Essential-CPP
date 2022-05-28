#include "LessThan.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_less_than(const vector<int> &vec, int comp)
{
    LessThan lt(comp);
    int count = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(lt(vec[i]))
            count++;
    }
    return count; 
}

void print_less_than(const vector<int> &vec, int comp, ostream &os = cout)
{
    LessThan lt(comp);
    vector<int>::const_iterator it = vec.begin();
    vector<int>::const_iterator end_it = vec.end();
    os << "elements less than " << lt.comp_val() << endl;
    while ((it = find_if(it, end_it, lt)) != end_it)
    {
        os << *it << " ";
        ++it;
    }
    
}

int main()
{
    int a[16] = {17, 12, 44, 9, 18, 45, 6, 14,
                 23, 67, 9, 0, 27, 55, 8, 16};
    vector<int> vec(a, a + 16);
    int comp_val = 20;
    cout << "Number of elements less than "
         << comp_val << " are "
         << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val);
}