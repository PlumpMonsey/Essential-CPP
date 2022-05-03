#include <iostream>
#include <string>
#include <vector>

int main()
{
    int usr_tries(0),usr_right(0);// 总猜测数，总正确数
    const int max_tries = 3;
    char usr_rsp;
    double usr_score = 0.0;
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
    int cur_tuple = 0;  // 索引

    // 用户想要猜测某个数列时
    while (next_seq)
    {
        // 显示数列
        std::cout << "The first second elements of the sequence are:"
                  << elem_seq[cur_tuple] << " " << elem_seq[cur_tuple+1]
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
            if(usr_guss == elem_seq[cur_tuple+2])
            {
                ++usr_right;
                got_it = true;
                std::cout << "Very goood.Yes "
                          << elem_seq[cur_tuple+2]
                          << " is the next element in the "
                          << seq_name[cur_tuple/3] << " sequence.\n";
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
        char try_again;
        std::cin >> try_again;
        if(try_again == 'n' || try_again == 'N')
            next_seq = false;
        else
            cur_tuple += 3;
    }// 外层循环结束
    return 0;
}