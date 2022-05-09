#include <iostream>
#include <vector>
#include <list>

template<typename IteratorType, typename elemType>
IteratorType _find(IteratorType first, IteratorType last, const elemType &value)
{
    for(; first != last; ++first)
        if(*first == value)
            return first;
    return last;
}

int main()
{
    const int asize = 8;
    int array[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    std::vector<int> ivec(array, array + asize);
    std::list<int> ilist(array, array + asize);

    int *ia = _find(array, array + asize, array[3]);
    std::vector<int>::iterator it = _find(ivec.begin(), ivec.end(), 5);
    std::list<int>::iterator iter = _find(ilist.begin(), ilist.end(), 1024);
    if(iter == ilist.end())
    {
        std::cout << "Not Found" << std::endl;
    }
}