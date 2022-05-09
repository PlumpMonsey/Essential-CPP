#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename elemType>
inline elemType* begin(const vector<elemType> &vec)
{
    return vec.empty() ? 0 : const_cast<elemType*>(&vec[0]);
}

template<typename elemType>
inline elemType* end(const vector<elemType> &vec)
{
    return vec.empty() ? 0 : const_cast<elemType*>(&vec[vec.size()]);
}


template<typename elemType>
elemType* find(const elemType* first, const elemType* last, const elemType &value)
{
    if(!first || !last)
        return 0;
    for(; first != last; ++first)
        if(*first == value)
            return const_cast<elemType*>(first);
    return 0;
}

int main()
{
    int iArr[5] = {0, 1, 2, 3, 4};
    string sArr[4] = {"Hello", "World", "And", "Goodbye"};
    vector<int> iVec = {0, 1, 2, 3, 4};
    vector<string> sVec = {"Hello", "World", "And", "Goodbye"};

    int *iA = find(iArr, iArr + 5, iArr[3]);
    string *sA = find(sArr, sArr + 4,sArr[2]);
    int *iV = find(begin<int>(iVec), end<int>(iVec), iVec[3]);
    string *sV = find(begin<string>(sVec), end<string>(sVec), sVec[2]);
    cout << *iA << " " << *sA << " " << *iV << " " << *sV << endl;
}