#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count0(string& s){
    int cnt = 0;
    for(auto& i: s){
        if(i=='0') ++cnt;
    }
    return cnt;
}

int count1(string& s){
    int cnt = 0;
    for(auto& i: s){
        if(i=='1') ++cnt;
    }
    return cnt;
}

// dp2[i][j] = max(
// dp1[i][j] do not chose this item,
// dp1[i-m][j-n] +1 chose this item)
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp1(m+1, vector<int>(n+1, 0));
    vector<vector<int>> dp2(m+1, vector<int>(n+1, 0));
    for(auto& s: strs){
        for(int i=0; i<=m; ++i){
            for(int j=0; j<=n; ++j){
                dp2[i][j] = dp1[i][j];
                int numZeros = count0(s);
                int numOnes = count1(s);
                if(i-numZeros>=0 && j-numOnes>=0){
                    dp2[i][j] = max(dp2[i][j], dp1[i-numZeros][j-numOnes]+1);
                }
            }
        }
        dp2.swap(dp1);
    }
    return dp1[m][n];
}


int main() {
    vector<string> strs {"10","0001","111001","1","0"};
    cout << findMaxForm(strs, 5, 3) << endl;
    return 0;
}
