#pragma once

#include <vector>

enum seq_name{
    Fibonacci, Lucas, Pell,
    Triangular, Squar, Pentagonal
};
void dispaly_msg(const std::string );
const std::vector<int>* fibo_seq(int);
const std::vector<int>* lucas_seq(int);
const std::vector<int>* pell_seq(int);
const std::vector<int>* triang_seq(int);
const std::vector<int>* squar_seq(int);
const std::vector<int>* pent_seq(int);
bool seq_elem(int, int&, const std::vector<int>* (*seq_ptr)(int));
bool size_is_ok(int);