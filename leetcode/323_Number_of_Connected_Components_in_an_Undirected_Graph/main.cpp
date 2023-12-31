#include <iostream>
#include <vector>
using namespace std;


class Solution {
    vector<int> s;
    int cnt;
public:
    int Find(int x){
        if(s[x]<0)return x;
        else return s[x] = Find(s[x]);
    }

    void Union(int x, int y){
        int p_x = Find(x);
        int p_y = Find(y);
        if(p_x != p_y){
            ++cnt;
            if(s[p_x]<=s[p_y]){
                s[p_x] += s[p_y];
                s[p_y] = p_x;
            }else{
                s[p_y] += s[p_x];
                s[p_x] = p_y;
            }
        }       
    }


    int countComponents(int n, vector<vector<int>>& edges) {
        cnt = 0;
        s.resize(n);
        fill(s.begin(), s.end(), -1);
        for(auto edge: edges){
            Union(edge[0], edge[1]);
        }
        return n-cnt;
    }
};


int main(){
    Solution s;
    vector<vector<int>> edges{{0,1}, {1,2}, {3,4}, {2,3}};
    cout << s.countComponents(5, edges) << endl;

    return 0;
}