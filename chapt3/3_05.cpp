#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool grow_vector(vector<int>& vec, int elem)
{
    while(vec.back() < elem)
        vec.push_back(vec.back() + vec[vec.size() - 2]);
    if(vec.back() > elem)
        return false;
    else
        return true;
}

bool is_elem(vector<int> &vec, int elem)
{
    int max_elem = vec.empty() ? 0 : vec.back();
    if(max_elem < elem)
        return grow_vector(vec, elem);
    if(max_elem == elem)
        return true;
    return binary_search(vec.begin(), vec.end(), elem);
}

int main()
{
    vector<int> vec = {1, 1, 2, 3, 5, 8};
    int elem;
    cin >> elem;
    cout << is_elem(vec, elem) << endl;
}