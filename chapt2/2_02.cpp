#include <iostream>
#include <vector>

void display(const std::vector<int>*);
void bubble_sort(std::vector<int>&);
void swap(int &v1, int &v2);

int main()
{
    int array[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    std::vector<int> vec(array, array + 8);
    std::cout << "Vector before sort: " << std::endl;
    display(&vec);
    std::cout << "Vector after sort: " << std::endl;
    bubble_sort(vec);
    display(&vec);
}

void display(const std::vector<int>* vec)
{
    if(!vec)
    {
        std::cout << "display(): the vector pointer is 0" << std::endl;
        return;
    }
    for(int i = 0; i < vec->size(); ++i)
    {
        std::cout << (*vec)[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(std::vector<int>& vec)
{
    for(int x = 0; x < vec.size(); ++x)
    {
        for(int y = x + 1; y < vec.size(); ++y)
        {
            if(vec[x] > vec[y])
                swap(vec[x], vec[y]);
        }
    }
}

void swap(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
