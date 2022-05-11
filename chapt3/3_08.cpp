#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    string s[] = {"dog", "cat", "apple"};
    set<string> word_exclusion(s, s + 3);
    map<string,int> words;
    string tword;
    while(cin >> tword)
    {
        if(word_exclusion.count(tword))
            continue;
        words[tword]++;
    }
    for(map<string, int>::iterator it = words.begin(); 
        it != words.end(); ++it)
    {
        cout << it->first << "[" << it->second << "]" << endl;
    }
}