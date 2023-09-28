#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string frequencySort(string s) {
    vector<pair<char, int>> table;
    int i;
    for(i=0; i<10; ++i) table.emplace_back((char)(i+'0'), 0);
    for(i=0; i<26; ++i) table.emplace_back((char)(i+'a'), 0);
    for(i=0; i<26; ++i) table.emplace_back((char)(i+'A'), 0);
    for(auto& c: s){
        if(c>='0' && c<='9'){
            table[c-'0'].second++;
        }else if(c>='a' && c<='z'){
            table[c-'a'+10].second++;
        }else{
            table[c-'A'+36].second++;
        }
    }
    sort(table.begin(), table.end(), [&](const pair<char, int>& a, const pair<char, int>& b)->bool {
        return a.second>b.second;
    });
    string ret;
    for(auto& iter: table){
        if(iter.second!=0){
            ret+= string(iter.second, iter.first);
        }
    }
    return ret;
}

int main() {
    string s = "priority0022334aaaaaaaAAAAAAAAAZZZZZZZZZzzzzzqueue";
    std::cout << frequencySort(s) << std::endl;
    return 0;
}
