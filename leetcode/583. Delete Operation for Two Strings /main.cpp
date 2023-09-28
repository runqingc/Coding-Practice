#include <iostream>
#include <string>
#include <vector>
using namespace std;

// dp[i][j]: the longest common substring in word1[0~i], word2[0~j]
// dp[i][j] = max(dp[i-1][j], dp[i][j-1], (if word1[i]==word2[j]) dp[i-1][j-1]+1)
int minDistance(string word1, string word2) {
    vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 0));
    for(int i=0; i<word1.size(); ++i){
        for(int j=0; j<word2.size(); ++j){
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            if(word1[i]==word2[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            }
        }
    }
    return (int)(word1.size()+word2.size()-2*dp[word1.size()][word2.size()]);
}

int main() {
    cout << minDistance("seagull", "eagle") << endl;
    return 0;
}
