#include "Stack.h"
#include <iostream>
using namespace std;

void fill_stack(Stack &stack, istream &is = cin)
{
    string str;
    while(is >> str && !stack.full())
    {
        stack.push(str);
    }
    cout << "Read in " << stack.size() << " elements." << endl;
}

int main()
{
    Stack s;
    string str;
    fill_stack(s);
    s.peek(str);
    cout << str << endl;
    s.pop(str);
    s.peek(str);
    cout << str << endl;
}