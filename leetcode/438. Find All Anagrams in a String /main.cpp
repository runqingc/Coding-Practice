#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSame(vector<int>& v1, vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if(p.size()>s.size()) return ans;
    vector<int> target(26,0);
    vector<int> current(26,0);
    for(auto& c: p){
        ++target[c-'a'];
    }
    for(int i=0; i<s.size(); ++i){
        ++current[s[i]-'a'];
        if(i>=p.size()){
            --current[s[i-(int)p.size()]-'a'];
        }
        if(isSame(target, current)){
            ans.push_back(i-(int)p.size()+1);
        }
    }
    return ans;

}


int main() {
    string s, p;
    s = "abab", p = "ab";

    vector<int> ans = findAnagrams(s, p);
    for(auto& i: ans){
        cout << i << " ";
    }
    return 0;
}
