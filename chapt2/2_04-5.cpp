#include <iostream>
#include <vector>
#include <fstream>
using std::ios_base;

const std::vector<int>* fibo_seq(int, std::istream& ,std::ostream&);
bool fibo_elem(int, int&, std::istream& ,std::ostream&);
bool file_in(std::vector<int>&, std::istream&);
bool file_out(const std::vector<int>&, int, int, std::ostream&);
bool size_is_ok(int);

int main()
{
    int pos;
    int elem = 0;
    std::ifstream ifile("data.txt");
    std::ofstream ofile("data.txt", ios_base::app);
    std::cout << "Please input a position : ";
    std::cin >> pos;
    if(fibo_elem(pos, elem, ifile, ofile))
        std::cout << "\nelement # " << pos
                  << " is " << elem << std::endl;
}

inline bool file_in(std::vector<int>& vec, std::istream& is)
{
    if(!is)
    {
        std::cerr << "Oops, unable to open infile!" << std::endl;
        return false;
    }else
    {
        int temp;
        is.seekg(0);
        while (is >> temp)
            vec.push_back(temp);
    }
    return true;
}
inline bool file_out(const std::vector<int>& vec, int start, int end, std::ostream& os)
{
    if(!os)
    {
        std::cerr << "Oops, unable to open outfile!" << std::endl;
        return false;
    }else
    {
        os.seekp(0, ios_base::end);
        for(int i = start + 1; i <= end; ++i)
        {
            os << vec[i - 1] << (!(i%10) ? "\n" : " ");
        }
    }
    return true;
}
inline bool size_is_ok(int pos)
{
    if(pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                  <<"-- cannot handle request!\n";
        return false;
    }
    return true;
}
const std::vector<int>* fibo_seq(int pos, std::istream &is, std::ostream &os)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> vec;
    if(!file_in(vec, is))
        return NULL;
    int oldSize = vec.size();

    for(int i = vec.size(); i < pos; ++i)
    {
        if(i <= 1)
            vec.push_back(1);
        else
            vec.push_back(vec[i - 1] + vec[i - 2]);
    }

    if(!file_out(vec, oldSize, pos, os))
        return NULL;

    return &vec;
}
inline bool fibo_elem(int pos, int& elem, std::istream &is, std::ostream &os)
{
    const std::vector<int>* pseq = fibo_seq(pos, is, os);
    if(!pseq)
    {
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}
