#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct character{
    int start;
    int end;
};
vector<int> partitionLabels(string s) {
    vector<struct character> alphabet(26);
    for(int i=0; i<26; i++){
        alphabet[i].start = 0; alphabet[i].end = 0;
    }
    for(int i=0; i<s.length(); i++){
        if(alphabet[s[i]-'a'].start == 0){
            alphabet[s[i]-'a'].start =i+1;
        }
        alphabet[s[i]-'a'].end = i+1;
    }
    vector<int> ans;
    sort(alphabet.begin(), alphabet.end(), [&](const struct character& a, const struct character& b)->bool{
        return a.start<b.start;
    });

    int i;
    for(i=0; alphabet[i].start==0; i++);
    int last_end = alphabet[i].end;
    for( ; i<26; i++){
        if(alphabet[i].start > last_end){
            ans.push_back(last_end);
            last_end = alphabet[i].end;
        }else{
            if(alphabet[i].end>last_end){
                last_end = alphabet[i].end;
            }
        }
    }
    ans.push_back(s.length());

    for(i=ans.size()-1; i>=1; i--){
        ans[i] = ans[i] - ans[i-1];
    }
    return ans;
}

int main() {
    string s = "caedbdedda";
    vector<int> ans = partitionLabels(s);
    for(auto& i: ans){
        cout << i << " ";
    }
    return 0;
}
