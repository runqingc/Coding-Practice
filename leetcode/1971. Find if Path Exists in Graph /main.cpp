#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>& S, int x){
    if (S[x] < 0) return x;
    else return S[x] = Find(S, S[x]);
}

void Union(vector<int>& S, int x, int y){
    int root_x = Find(S, x);
    int root_y = Find(S, y);
    if(S[root_y]<S[root_x]){
        swap(x, y);
    }
    S[root_x] += S[root_y];
    S[root_y] = root_x;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<int> S = vector<int>(n, -1);
    for(auto edge: edges){
        if(Find(S, edge[0])!= Find(S, edge[1])){
            Union(S, edge[0], edge[1]);
        }
    }
    return Find(S, source)== Find(S, destination);
}



int main() {
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    cout << validPath(6, edges, 4, 5);
    return 0;
}
