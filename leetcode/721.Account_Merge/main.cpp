#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    for(auto i: v){ os << i << " ";}
    return os << endl;   
}

class Solution {
    vector<int> S;

public:

    int Find(int x){
        if(S[x]<0) return x;
        return S[x] = Find(S[x]);
    }

    void Union(int x, int y){
        int px = Find(x);
        int py = Find(y);
        if(px != py){
            if(S[px]<=S[py]){
                S[px] += S[py];
                S[py] = px;
            }else{
                S[py] += S[px];
                S[px] = py;
            }
        }
    }



    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string, string> names;
        unordered_map<string, int> id;
        unordered_map<int, string> email;
        unordered_map<int, int> roots;
        vector<vector<string>> ans;
        int cnt = 0;
        for(auto account: accounts){
            for(int i=1; i<account.size(); ++i){
                names[account[i]] = account[0];
                // generate id
                if(id.find(account[i])==id.end()){
                    id[account[i]] = cnt;
                    email[cnt] = account[i];
                    ++cnt;
                    S.emplace_back(-1);
                }
                int first_id = id[account[1]];
                int this_id = id[account[i]];
                if(i>1){
                    Union(first_id, this_id);
                }
            }
        }
        for(int i=0; i<S.size(); ++i){
            if(S[i]<0){
                ans.push_back({names[email[i]]});
                roots[i] = (int)ans.size()-1;
            }
        }
        for(int i=0; i<S.size(); ++i){
            ans[roots[Find(i)]].push_back(email[i]);
        }

        for(auto& acc: ans){
            sort(acc.begin()+1, acc.end());
        }

        return ans;
    }
};




int main(){

    Solution s;

    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
    {"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

    cout << s.accountsMerge(accounts);
    
    return 0;
}