#include <iostream>
#include <vector>
#include <string>

template<typename T>
void dispaly_msg(const std::string s, const std::vector<T> vec)
{
    std::cout << s << " ";
    for(auto a: vec)
    {
        std::cout << a << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::string s = "Hello, world";
    std::vector<std::string> vec;
    vec.push_back("and");
    vec.push_back("goodbye");
    dispaly_msg(s, vec);
}
