#include <iostream>
#include <string>
using namespace std;



string shortestBeautifulSubstring(string s, int k) {
    int cur1=0;
    int i=0, j=0;
    string max;
    for( ; j<s.size(); ){
        if(s[j]=='1'){
            ++cur1;
        }
        if(cur1>=k){
            while(cur1>=k && i<=j){
                if(cur1==k){
                    if(max.empty() || (j-i+1<max.length())|| (j-i+1==max.length() && s.substr(i, j-i+1)<max)){
                        max=s.substr(i, j-i+1);
                    }
                }
                if(s[i]=='1'){
                    --cur1;
                }
                ++i;
            }
            if(cur1<k){
                --i;
            }
            ++j;
        }else{
            // cur1<k
            ++j;
        }

    }

    while(cur1==k && i<s.size()){
        if(max.empty() || (j-i<max.length())|| (j-i==max.length() && s.substr(i, j-i+1)<max)){
            max=s.substr(i, j-i+1);
        }
        if(s[i]=='1'){
            --cur1;
        }
        ++i;
    }

    return max;
}

int main() {

    string s = "100011001"; int k = 3;
    cout << shortestBeautifulSubstring(s, k);
    return 0;
}
