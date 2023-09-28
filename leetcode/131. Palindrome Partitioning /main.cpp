#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;

    static bool isPalindrome(string::iterator i, string::iterator j){
        for(; i<j; ++i, --j){
            if(*i!=*j) return false;
        }
        return true;
    }

    void dfs(string& s, string::iterator i){

        for(int j=0; i+j<s.end(); ++j){
            if(isPalindrome(i, i+j)){
                cur.emplace_back(i, i+j+1);
                if(i+j==s.end()-1) ans.push_back(cur);
                dfs(s, i+j+1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, s.begin());
        return ans;
    }
};


int main() {
    Solution s1;
    s1.ans = s1.partition("aab");
    for(auto& i: s1.ans){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
