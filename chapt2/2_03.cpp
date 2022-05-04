#include <iostream>
#include <vector>
#include <fstream>

void display(const std::vector<int>*, std::ostream &os = std::cout);
void bubble_sort(std::vector<int>&, std::ofstream *ofil = 0);
void swap(int &v1, int &v2);

int main()
{
    int array[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    std::ofstream ofil("data.txt");
    std::vector<int> vec(array, array + 8);
    std::cout << "Vector before sort: " << std::endl;
    display(&vec);
    std::cout << "Vector after sort: " << std::endl;
    bubble_sort(vec, &ofil);
    display(&vec);
}

void display(const std::vector<int>* vec, std::ostream &os)
{
    if(!vec)
    {
        os << "display(): the vector pointer is 0" << std::endl;
        return;
    }
    for(int i = 0; i < vec->size(); ++i)
    {
        os << (*vec)[i] << " ";
    }
    os << std::endl;
}

void bubble_sort(std::vector<int>& vec, std::ofstream* ofil)
{
    for(int x = 0; x < vec.size() - 1; ++x)
        for(int y = x + 1; y < vec.size(); ++y)
        {
            if(vec[x] > vec[y])
                if(ofil)
                {
                    display(&vec, (*ofil));
                    (*ofil) << "about to call swap! x: " << x
                            << " y: " << y << "\tswapping: "
                            << vec[x] << " with " << vec[y] << std::endl;
                }
                swap(vec[x], vec[y]);
        }
}

void swap(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}