#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int n;
    int id = 1;
    vector<pair<int, int>> cur;
    vector<int> islandSize {0};


    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(grid[i][j]==0 || visited[i][j]) return;
        visited[i][j] = true;
        cur.emplace_back(i, j);
        // try to visit all the legal adjacent nodes
        if(i-1>=0){
            dfs(grid, visited, i-1, j);
        }
        if(i+1<n){
            dfs(grid, visited, i+1, j);
        }
        if(j-1>=0){
            dfs(grid, visited, i, j-1);
        }
        if(j+1<n){
            dfs(grid, visited, i, j+1);
        }

    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> tmp;

        n = (int) grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, true));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]){
                    visited[i][j] = false;
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(!visited[i][j]){
                    dfs(grid, visited, i, j);
                    for(auto& pos: cur){
                        grid[pos.first][pos.second] = id;
                    }
                    islandSize.push_back((int)cur.size());
                    cur=tmp;
                    ++id;
                }
            }
        }

        // find all the water grid, check their adjacent node
        int max_size;
        max_size=max(*max_element(islandSize.begin(), islandSize.end()), 1);

        int this_size=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                vector<int> near;
                if(grid[i][j]==0){
                    // try to visit all the legal adjacent nodes
                    if(i-1>=0 && grid[i-1][j]>0){
                        near.push_back(grid[i-1][j]);
                    }
                    if(i+1<n && grid[i+1][j]>0){
                        near.push_back(grid[i+1][j]);
                    }
                    if(j-1>=0 && grid[i][j-1]>0){
                        near.push_back(grid[i][j-1]);
                    }
                    if(j+1<n && grid[i][j+1]>0){
                        near.push_back(grid[i][j+1]);
                    }

                    // all adjacent land node should be inserted
                    // case 1: no land
                    // case 2: 1 land
                    // case 3: join two land
                    // case 4: 2 or more lands from same island, expand size+1
                    // find max
                    if(near.empty()){
                        continue;
                    }else{
                        std::sort(near.begin(), near.end());
                        this_size = 1;
                        for(int a=0; a<near.size(); ++a){
                            // if neighbors are from same island
                            if(a>0 && near[a]==near[a-1]){
                                if(islandSize[near[a]]+1>max_size){
                                    max_size = islandSize[near[a]]+1;
                                }
                            }else{
                                this_size += islandSize[near[a]];
                                if(this_size>max_size){
                                    max_size = this_size;
                                }
                            }

                        }
                    }
                }
            }
        }

        return max_size;
    }
};




int main() {
//    vector<vector<int>> graph{{0,0,1,0,0,0,0,1,0,0,0,0,0},
//                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
//                              {0,1,1,0,1,0,0,0,0,0,0,0,0},
//                              {0,1,0,0,1,1,0,0,1,0,1,0,0},
//                              {0,1,0,0,1,1,0,0,1,1,1,0,0},
//                              {0,0,0,0,0,0,0,0,0,0,1,0,0},
//                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
//                              {0,0,0,0,0,0,0,1,1,0,0,0,0},
//                              {0,0,0,0,0,0,0,0,0,0,0,0,0},
//                              {0,0,0,0,0,0,0,0,0,0,0,0,0},
//                              {0,0,0,0,0,0,0,0,0,0,0,0,0},
//                              {0,0,0,0,0,0,0,0,0,0,0,0,0},
//                              {0,0,0,0,0,0,0,0,0,0,0,0,0},
//                              };
    vector<vector<int>> graph{{1,1,1},{1,0,0},{1,1,1}};
    Solution s1;
    cout << s1.largestIsland(graph);

    return 0;
}
