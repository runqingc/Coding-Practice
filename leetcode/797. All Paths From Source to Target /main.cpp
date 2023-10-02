#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> ans;
vector<int> cur{0};

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& connect, int pos){
    if(graph[pos].empty()) return;
    
    for(auto& next: graph[pos]){
        if(connect[pos][next]){
            cur.push_back(next);
            connect[pos][next] = false;
            if(next==graph.size()-1){
                ans.push_back(cur);
            }else{
                dfs(graph, connect, next);
            }
            cur.pop_back();
            connect[pos][next] = true;
        }

    }
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<bool>> connect(graph.size(), vector<bool>(graph.size(), false));
    for(int i=0; i<graph.size(); ++i){
        for(auto& j: graph[i]){
            connect[i][j] = true;
        }
    }
    dfs(graph, connect, 0);
    return ans;
}


int main() {
    vector<vector<int>> g{{4,3,1},{3,2,4},{3},{4},{}};
    auto ret = allPathsSourceTarget(g);
    for(auto& i: ret){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
