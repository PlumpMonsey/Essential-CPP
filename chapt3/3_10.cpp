#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;
    vector<string> vec;
    copy(is, eof, back_inserter(vec));
    sort(vec.begin(), vec.end());
    ostream_iterator<string> os(cout, " ");
    copy(vec.begin(), vec.end(), os);
}