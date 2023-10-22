#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxProduct(vector<string>& words) {

    vector<int> bit(26, 0);
    bit[0] = 1;
    for(int i=1; i<26; ++i){
        bit[i] = bit[i-1]<<1;
    }
    vector<int> binary(words.size(), 0);
    for(int i=0; i<words.size(); ++i){
        for(char c: words[i]){
            binary[i] |= bit[c-'a'];
        }
    }
    int max = 0;
    for(int i=0; i<binary.size(); ++i){
        for(int j=i+1; j<binary.size(); ++j){
            if((binary[i]&binary[j])==0){
                if(words[i].size()*words[j].size()>max){
                    max = words[i].size()*words[j].size();
                }
            }
        }
    }
    return max;
}



int main() {

    vector<string> words{"a","aa","aaa","aaaa"};
    cout << maxProduct(words)<< endl;

    return 0;
}
