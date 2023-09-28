#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ip;
    string cur;

    // [l, r)
    void dfs(string::iterator l, string::iterator r, int numCanUse){

        // for every possible string
        // case 3: 3 digits
        if(r-l>=3){
            string tmp(l, l+3);
            // check if tmp is valid
            if(tmp[0]!='0' && stoi(tmp)<=255){
                cur += tmp;
                --numCanUse;
                if(numCanUse==0 && r-l==3){
                    ip.push_back(cur);
                }else if(r-l-3>=numCanUse && r-l-3<=3*numCanUse){
                    cur+=".";
                    dfs(l+3, r, numCanUse);
                    cur.pop_back();
                }
                cur.pop_back(); cur.pop_back();cur.pop_back();
                ++numCanUse;
            }
        }
        // case 2: 2 digits
        if(r-l>=2){
            string tmp(l, l+2);
            // check if tmp is valid
            if(tmp[0]!='0'){
                cur += tmp;
                --numCanUse;
                if(numCanUse==0 && r-l==2){
                    ip.push_back(cur);
                }else if(r-l-2>=numCanUse && r-l-2<=3*numCanUse){
                    cur+=".";
                    dfs(l+2, r, numCanUse);
                    cur.pop_back();
                }
                cur.pop_back(); cur.pop_back();
                ++numCanUse;
            }
        }
        // case 1: 1 digit
        if(r-l>=1){
            cur += *l;
            --numCanUse;
            if(numCanUse==0 && r-l==1){
                ip.push_back(cur);
            }else if(r-l-1>=numCanUse && r-l-1<=3*numCanUse){
                cur+=".";
                dfs(l+1, r, numCanUse);
                cur.pop_back();
            }
            cur.pop_back();
            ++numCanUse;
        }

    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12 || s.size()<4) return ip;
        dfs(s.begin(), s.end(), 4);
        return ip;
    }
};

int main() {
    Solution s1;
    vector<string> ans  = s1.restoreIpAddresses("25525511135");

    for(auto& s:ans){
        cout << s << endl;
    }
    return 0;
}
