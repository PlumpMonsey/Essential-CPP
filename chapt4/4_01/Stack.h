#pragma one
#include <vector>
#include <string>

class Stack{
private:
    std::vector<std::string> _stack;
public:
    bool full();
    bool empty();
    bool push(const std::string&);
    bool pop(std::string&);
    bool peek(std::string&); 
    int size(){ return _stack.size(); }
};