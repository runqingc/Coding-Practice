#include <iostream>
#include <string>
#include <queue>
using namespace std;


// r 不断从左往右移动
// 当前l-r的区间里是否包含全部字符
//      如果不是，就继续向右移动r
//      如果是，就向右移动l以得到最小长度的符合字符串
string minWindow(string s, string t) {
    vector<int> bucket(128, 0);
    vector<bool> exist(128, false);
    // count the characters in t
    for(auto& c: t){
        bucket[(int)c]++; exist[(int)c] = true;
    }
    int l=0, r=0, cnt=0, start=0, end=INT_MAX;
    for( ; r<s.size(); r++){
        if(exist[s[r]]){
            if(bucket[s[r]]>0){
                cnt++;
            }
            bucket[s[r]]--;
            if(cnt==t.size()){
                while(1){
                    if(!exist[s[l]]) l++;
                    else if(exist[s[l]] && bucket[s[l]]<0){
                        bucket[s[l]]++;l++;
                    }else break;
                }
                if(r-l<end-start){
                    start = l; end = r;
                }
            }
        }
    }
    if(cnt<t.size()) return "";
    else return s.substr(start, end-start+1);
}

int main() {
    string s("BDOAECODEBANC"), t("ABC");
    cout << minWindow(s, t) << endl;
    return 0;
}
