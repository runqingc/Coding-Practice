#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, vector<vector<int>>& isConnected, vector<int>& visited){
    visited[x] = 1;
    for(int i=0; i<visited.size(); ++i){
        if(i!=x && visited[i]==0 && isConnected[i][x]==1){
            dfs(i, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int cnt = 0;
    for(int i=0; i<isConnected.size(); ++i){
        if(visited[i]==0){
            cnt++;
            dfs(i, isConnected, visited);
        }
    }
    return cnt;
}

int main() {
    vector<vector<int>> isConnected {{1,1,0},{1,1,0},{0,0,1}};
    std::cout << findCircleNum(isConnected) << std::endl;
    return 0;
}
