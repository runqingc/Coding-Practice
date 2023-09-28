#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

#define MAX 310
bool wordBreak(string s, vector<string>& wordDict) {
    // build the hash table
    unordered_set<string> dict;
    for(auto& word: wordDict){
        if(dict.find(word)==dict.end()){
            dict.insert(word);
        }
    }

    // dp[i]: if the first i characters of s can be break
    vector<bool> dp(MAX, false);
    dp[0] = true;
    for(int i=0; i<s.length(); ++i){
        for(int j=1; j<=i+1 && j<=20; ++j){
            string subString = s.substr(i+1-j, j);
            if(dict.find(subString)!=dict.end() && dp[i+1-j]){
                dp[i+1] = true;
            }
        }
    }
    return dp[s.length()];
}

int main() {
    string s("catsandog");
    vector<string> wordDict{"cats","dog","sand","and","cat"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}
