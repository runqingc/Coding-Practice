#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> s;
    int cnt=0;
public:
    int Find(int x){
        if(s[x]<0) return x;
        else return s[x] = Find(s[x]);
    }

    void Union(int x, int y){
        int px = Find(x);
        int py = Find(y);
        if(px!=py){
            ++cnt;
            if(s[px]<=s[py]){
                s[px]+=s[py];
                s[py] = px;
            }else{
                s[py]+=s[px];
                s[px] = py;
            }
        }
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        s.resize(n);
        fill(s.begin(), s.end(), -1);
        for(auto& edge: edges){
            Union(edge[0], edge[1]);
        }
        return n-cnt==1;
    }
};

int main(){
    Solution s;    
    vector<vector<int>> edges{{0,1}, {1,2}, {3,4}, {2,3}};
    cout << boolalpha;
    cout << s.validTree(5, edges);
    

    return 0;
}