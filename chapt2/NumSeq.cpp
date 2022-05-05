#include <iostream>
#include "NumSeq.h"

void dispaly_msg(const std::string s)
{
    std::cout << s <<  std::endl;
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
const std::vector<int>* fibo_seq(int pos)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> fibo;

    for(int i = fibo.size(); i < pos; ++i)
    {
        if(i <= 1)
            fibo.push_back(1);
        else
            fibo.push_back(fibo[i - 1] + fibo[i - 2]);
    }
    return &fibo;
}
const std::vector<int>* lucas_seq(int pos)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> lucas;

    for(int i = lucas.size(); i < pos; ++i)
    {
        if(i == 0)
            lucas.push_back(1);
        else if(i == 1)
            lucas.push_back(3);
        else
            lucas.push_back(lucas[i - 1] + lucas[i - 2]);
    }
    return &lucas;
}
const std::vector<int>* pell_seq(int pos)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> pell;

    for(int i = pell.size(); i < pos; ++i)
    {
        if(i == 0)
            pell.push_back(1);
        else if(i == 1)
            pell.push_back(2);
        else
            pell.push_back(2 * pell[i - 1] + pell[i - 2]);
    }
    return &pell;
}
const std::vector<int>* triang_seq(int pos)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> triang;

    for(int i = triang.size(); i < pos; ++i)
    {
        triang.push_back((i + 1) * (i + 2) / 2);
    }
    return &triang;
}
const std::vector<int>* squar_seq(int pos)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> squar;

    for(int i = squar.size(); i < pos; ++i)
    {
        squar.push_back((i + 1) * (i + 1));
    }
    return &squar;
}
const std::vector<int>* pent_seq(int pos)
{
    if(!size_is_ok(pos))
    {
        return NULL;
    }

    static std::vector<int> pent;

    for(int i = pent.size(); i < pos; ++i)
    {
        pent.push_back((i + 1) * (3 * i + 2) / 2);
    }
    return &pent;
}

bool seq_elem(int pos, int& elem, const std::vector<int>* (*seq_ptr)(int))
{
    if(!seq_ptr)
    {
        dispaly_msg("Internal Error: seq_ptr is set to null");
    }
    const std::vector<int>* pseq = seq_ptr(pos);
    if(!pseq)
    {
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    return true;
}