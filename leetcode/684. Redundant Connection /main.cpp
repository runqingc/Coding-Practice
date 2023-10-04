#include <iostream>
#include <vector>
using namespace std;

vector<int> S;

int Find(int x){
    if(S[x]<0) return x;
    else return S[x] = Find(S[x]);
}

void Union(int x, int y){
    int root_x = Find(x);
    int root_y = Find(y);
    if(S[root_y]<S[root_x]){
        swap(root_x, root_y);
    }
    S[root_x] += S[root_y];
    S[root_y] = root_x;
}


vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    for(int i=0; i<edges.size(); ++i){
        S.emplace_back(-1);
    }
    for(auto edge:edges){
        if(Find(edge[0])== Find(edge[1])){
            return edge;
        }else{
            Union(edge[0], edge[1]);
        }
    }
    return edges.back();
}


int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    auto ans = findRedundantConnection(edges);
    cout << ans[0] << ", " << ans[1];
    return 0;
}
