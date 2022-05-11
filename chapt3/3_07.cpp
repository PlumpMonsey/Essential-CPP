#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string,int> words;
    string tword;
    while(cin >> tword)
    {
        words[tword]++;
    }
    for(map<string, int>::iterator it = words.begin(); 
        it != words.end(); ++it)
    {
        cout << it->first << "[" << it->second << "]" << endl;
    }
}