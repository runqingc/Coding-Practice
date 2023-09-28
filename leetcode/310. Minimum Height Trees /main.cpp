#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


// topological sorting， until there's 1 or 2 point left
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==1) return vector<int>{0};
    unordered_map<int, vector<int>> adjList;
    vector<int> degree(n, 0);
    vector<int> ans;
    // construct the adjacent list
    for(auto& edge: edges){
        adjList[edge.front()].push_back(edge.back());
        adjList[edge.back()].push_back(edge.front());
        ++degree[edge.front()];
        ++degree[edge.back()];
    }
    // enqueue all the node degree 1
    queue<int> q;
    for(int i=0; i<n; ++i){
        if(degree[i]==1){
            q.emplace(i);
        }
    }
    int cnt = 0;
    int num;
    while(!q.empty()){
        num = (int) q.size();
        cnt += num;
        if(cnt==n){
            while(!q.empty()){
                ans.push_back(q.front()); q.pop();
            }
            return ans;
        }
        while(num--){
            int node = q.front();
            q.pop();
            // for all node adjacent to node, degree--
            for(auto& adj: adjList[node]){
                --degree[adj];
                if(degree[adj]==1){
                    q.emplace(adj);
                }
            }

        }
    }


    return ans;
}

int main() {
    int n = 7;
    vector<vector<int>> edges {{0,1},{1,2},{1,3},{2,4},{3,5},{4,6}};
    auto ans = findMinHeightTrees(n, edges);
    for (auto &i: ans)
        cout << i << " ";
    return 0;
}
