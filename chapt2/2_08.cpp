#include <iostream>
#include "NumSeq.h"

int main()
{
    const std::vector<int>* (*seq_arr[])(int) = {
        fibo_seq, lucas_seq, pell_seq,
        triang_seq, squar_seq, pent_seq
    };
    const std::vector<int>* (*seq_ptr)(int) = seq_arr[0];
    int pos;
    int elem = 0;
    std::cout << "Please input a position : ";
    std::cin >> pos;
    if(seq_elem(pos, elem, seq_ptr))
        std::cout << "\nelement # " << pos
                  << " is " << elem << std::endl;
}
