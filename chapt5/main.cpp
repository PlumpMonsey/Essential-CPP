#include "fibonacci.hpp"

int main()
{
    Fibonacci fib(16);
    cout << fib << endl;
    num_sequence* ns = new Fibonacci(8, 12);
    cout << *ns << endl;
    cout << fib.what_am_i() << endl;
    cout << ns->what_am_i() << endl;
}