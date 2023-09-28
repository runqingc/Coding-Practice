#include <iostream>
#include <string>
#include <vector>
using namespace std;

// dp[i][j] if s.substring(i, j) is palindrome
// dp[i][j] = 0, if
//            1, if(dp[i+1][j-2]) is palindrome && s[i+1]==s[j-2]

int countSubstrings(string s) {
    int size = (int)s.size();
    vector<vector<bool>> dp(size+1, vector<bool>(size+1, true));
    int cnt = (int)s.size();
    for(int j=2; j<=size; ++j){
        for(int i=0; i<size; ++i){
            if(i+j-1>=size) continue;
            if(s[i]==s[i+j-1] && dp[i+1][j-2]){
                ++cnt;
            }else{
                dp[i][j] = false;
            }
        }
    }

    return cnt;
}



int main() {
    cout << countSubstrings("leetcode");
    return 0;
}
