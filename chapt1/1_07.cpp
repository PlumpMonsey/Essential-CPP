#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

int main()
{
    int usr_tries(0),usr_right(0);// 总猜测数，总正确数
    std::string usr_name;
    const int max_tries = 3;
    char usr_rsp;
    bool go_for_it = true;       // 用户想继续猜
    bool next_seq = true;        // 显示下一个数列
    bool got_it = false;         // 用户是否答对
    const int seq_size = 18;     
    const int max_seq = 6;
    int elem_seq[seq_size] = {
        1, 2, 3,        // Fibonacci
        3, 4, 7,        // Lucas
        2, 5, 12,       // Pell
        3, 6, 10,       // Triangular
        4, 9, 16,       // Squar
        5, 12, 22       // Pentagonal
    };
    std::string seq_name[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Squar",
        "Pentagonal"
    };

    std::vector<int> fibonacci(elem_seq,elem_seq + 3), 
                     lucas(elem_seq + 3,elem_seq + 6), 
                     pell(elem_seq + 6,elem_seq + 9), 
                     triangular(elem_seq + 9,elem_seq + 12), 
                     squar(elem_seq + 12,elem_seq + 15), 
                     pentagonal(elem_seq + 15,elem_seq + 18);
    std::vector<int> *seq_addrs[max_seq] = {
        &fibonacci, &lucas, &pell,
        &triangular, &squar, &pentagonal
    };

    int seq_index = 0;
    std::vector<int> *cur_seq = 0;
    srand(time(NULL));
    
    std::ifstream infile("seq_data.txt");
    if(!infile)
        std::cerr << "Oops, unable to open file!" << std::endl;
    else
    {
        std::string name;
        int nt;         // 猜的总次数
        int nc;         // 猜对的次数
        int find = 0;
        while (infile >> name)
        {
            infile >> nt >> nc;
            if(name == usr_name)
            {
                find = 1;
                usr_tries = nt;
                usr_right = nc;
            }
        }  
        if(find == 1){
        std::cout << "Welcome back, " << usr_name
            << "TOT[" << nt << "]" 
            << "RIGHT[" << nc << "]" 
            << "\nGood, Luck!" << std::endl;
        }else
            std::cout << "Welcome, freshman " << usr_name << std::endl;
    }

    // 用户想要猜测某个数列时
    while (next_seq)
    {
        seq_index = rand() % max_seq;
        cur_seq = seq_addrs[seq_index];
        // 显示数列
        std::cout << "The first second elements of the sequence are:"
                  << (*cur_seq)[0] << " " << (*cur_seq)[1]
                  << "\nWhat is the next?";
        int tries_cnt = 0;
        usr_tries = 0;
        go_for_it = true;
        got_it = false;
        // 用户所猜答案不正确且用户想再猜一次
        while (!got_it && go_for_it && tries_cnt++ < max_tries)
        {
            int usr_guss;
            std::cin >> usr_guss;
            ++usr_tries;
            // 如果用户猜对
            if(usr_guss == (*cur_seq)[2])
            {
                ++usr_right;
                got_it = true;
                std::cout << "Very goood.Yes "
                          << (*cur_seq)[2]
                          << " is the next element in the \""
                          << seq_name[seq_index] << "\" sequence.\n";
            }else{
                // 猜错
                switch (tries_cnt)
                {
                case 1:
                    std::cout << "Oops! Nice guss but not quite it." << std::endl;
                    break;
                case 2:
                    std::cout << "Hmm. Sorry. Wrong a second time." << std::endl;
                    break;
                case 3:
                    std::cout << "Ah, this is harder than it looks, isn't it?" << std::endl;
                    break;
                default:
                    std::cout << "It must be getting pretty frustrating by now!" << std::endl;
                    break;
                }
                std::cout << "do you want to continue?(y/n):" << std::endl;
                std::cin >> usr_rsp;
                if(usr_rsp == 'n' || usr_rsp == 'N')
                    go_for_it = false;
            }
        } // 内层循环结束
        std::cout << "Want try another sequence?(y/n)" << std::endl;
        std::cin >> usr_rsp;
        if(usr_rsp == 'n' || usr_rsp == 'N')
            next_seq = false;
    }// 外层循环结束

    std::ofstream outfile("seq_data.txt", std::ios_base::app);
    if(!outfile)
        std::cerr << "Oops, unable to open file!" << std::endl;
    else
    {
        outfile << usr_name << ' '
                << usr_tries << ' ' 
                << usr_right << std::endl;
    }
    return 0;
}