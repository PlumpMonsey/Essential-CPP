#include <iostream>

bool fibon_elem(int, int&);
bool print_sequence(int);

int main()
{
    char usr_rsp = 'y';
    int elem = 0;
    int pos = 0;
    while(usr_rsp == 'y' || usr_rsp == 'Y')
    {
        std::cout << "Please input a position : ";
        std::cin >> pos;
        if(fibon_elem(pos, elem))
            std::cout << "element # " << pos
                    << " is " << elem << std::endl;
        else
            std::cout << "Sorry.Could not calculate element #"
                      << pos << std::endl;
        std::cout << "Want try another pos?(y/n): ";
        std::cin >> usr_rsp;
    }
}

bool fibon_elem(int pos, int& elem)
{
    if(pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }
    elem = 1;
    int n1 = 1, n2 = 1;
    for(int i = 3; i <= pos; ++i)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
    }
    return true;
}

bool print_sequence(int pos)
{
    if(pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                  <<"-- cannot handle request!\n";
        return false;
    }
    std::cout << "The sequence for " << pos << " position:\n\t";
    switch (pos)
    {
    default:
    case 2:
        std::cout << "1 ";
    case 1:
        std::cout << "1 ";
        break;
    }
    
    int n1 = 1, n2 = 1, elem = 1;
    for(int i = 3; i <= pos; ++i)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
        std::cout << elem << (!(i%10) ? "\n\t" : " ");
    }
    std::cout << std::endl;
    return true;
}
