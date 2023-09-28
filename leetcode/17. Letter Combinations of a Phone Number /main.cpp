#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> map{"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    for(auto num: digits){
        int n = (int)(num-'0');
        if(ans.empty()){
            for(auto c: map[n]){
                ans.emplace_back(1, c);
            }
        }else{
            int cnt = (int) ans.size();
            int multiple = (int)map[n].size();
            // duplicate 3 or 4 times
            for(int i=0; i<multiple-1; ++i){
                for(int j=0; j<cnt; ++j){
                    ans.push_back(ans[j]);
                }
            }
            // first 1/3, char[0], 1/3 - 2/3 char[1]..
            int i = 0;
            int last_i = 0;
            for(int k = 0; k<multiple; ++k){
                for( ; i<last_i+cnt; ++i){
                    ans[i]+=string(1, map[n][k]);
                }
                last_i = i;
            }
        }
    }
    return ans;
}


int main() {
    string digits = "234";
    vector<string> ans = letterCombinations(digits);
    for(auto& s:ans){
        cout << s << endl;
    }
    return 0;
}
