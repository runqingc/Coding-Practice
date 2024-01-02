#include <iostream>
#include <vector>
using namespace std;

// solution1: dfs

// solution2: dp

class Solution {
    bool found = false;
public:

    void dfs(string& s1, string& s2, string& s3, int index1, int index2){
        if(!found){
            int index3 = index1 + index2;
            if(index3>=s3.length()){
                found = true;
                return ;
            }
            if(index1<s1.length() && s3[index3]==s1[index1]){
                dfs(s1,s2,s3,index1+1, index2);
            }
            if(index2<s2.length() && s3[index3]==s2[index2]){
                dfs(s1,s2,s3,index1, index2+1);
            }
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        if(s3.empty()) return true;
        dfs(s1,s2,s3,0,0);
        return found;
    }
};

int main(){
    

    return 0;
}
