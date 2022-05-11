#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

template <typename InputIteator, typename OutputIteator,
          typename ElemType, typename Comp>
OutputIteator 
filter(InputIteator first, InputIteator last, OutputIteator at, const ElemType &vule, Comp pred)
{
    while( (first = find_if(first, last, bind2nd(pred, vule))) != last)
    {
        *at++ = *first++;
    }
    return at;
}

template <typename InputIteator, typename OutputIteator,
          typename ElemType, typename Comp>
OutputIteator
sub_vec(InputIteator first, InputIteator last, OutputIteator at, const ElemType &vule, Comp pred)
{
    OutputIteator end = at;
    while(first != last)
    {
        *end++ = *first++;
    }
    sort(at, end);
    OutputIteator it = find_if(at, end, bind2nd(pred, vule));
    while(it != end)
    {
        *it++ = 0;
    }
    return at;
}
int main()
{
    const int size = 8;
    int a[size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> vec;
    filter(a, a + size, back_inserter(vec), size, less<int>());
    for(auto elem : vec)
        cout << elem << ' ';
    cout << endl;
    // sub_vec(a, a + size, vec.begin(), size, greater<int>());
    // for(auto elem : vec)
    //     cout << elem << ' ';
    //cout << endl;
}