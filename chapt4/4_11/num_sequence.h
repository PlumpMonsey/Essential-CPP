#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class num_sequence
{
public:
    enum seq_name{
        unset,
        Fibonacci, Lucas, Pell,
        Triangular, Squar, Pentagonal
    };

    typedef void (num_sequence::*PtrType)(int);
    void fibo_seq(int);
    void lucas_seq(int);
    void pell_seq(int);
    void triang_seq(int);
    void squar_seq(int);
    void pent_seq(int);
    void set_sequence(seq_name);
    bool check_integrity(int);
    int elem(int);
    static int num_of_sequence() {return num_seq;}
    const string what_am_i() const;
    void display(ostream& os, num_sequence &ns, const int pos);
    static seq_name nstype(int num)
    {
        return num<=0 || num >= num_seq
               ? unset
               : static_cast<seq_name>(num);
    }
private:
    vector<int>* _elem;  // 当前数列的元素
    PtrType _pmf;        // 指向目前所用算法（计算数列）
    seq_name _isa;       // 当前数列的名字
    static const int num_seq = 7;
    static PtrType func_tbl[num_seq];
    static vector<vector<int> > seq;
};