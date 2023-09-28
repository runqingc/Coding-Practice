#include <iostream>
#include <string>
using namespace std;

int KMP(string& haystack, string& needle){
    int m= (int)needle.size();
    vector<int> next(m, 0);
    int i, j;
    for(i=0, j = 1; j<=m-2; ++j){
        if(needle[i]==needle[j]){
            next[j+1] = i+1;
            ++i;
        }else{
            for( ; i>0 && needle[i]!=needle[j]; i = next[i]);
            if(needle[i]==needle[j]){
                ++i; next[j+1] = i;
            }else{
                next[j+1] = 0;
            }
        }
    }

    j = 0;
    for(i=0; i<haystack.size(); ){
        // if match
        if(haystack[i]==needle[j]){
            if(j==needle.size()-1){
                return i-m+1;
            }
            ++j, ++i;
        }
            // if not match
        else{
            if(j==0){
                ++i;
            }else{
                j = next[j];
            }
        }
    }
    return -1;
}


bool repeatedSubstringPattern(string s) {
    string s2 = s.substr(1) + s.substr(0, s.size()-1);
    return KMP(s2, s)!=-1;
}


int main() {
    cout << repeatedSubstringPattern("");
    return 0;
}
