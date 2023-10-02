#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int m;
int n;
bool flag = true;
int cur = 0;

vector<pair<int, int>> findNeighbor(vector<vector<bool>>& visited, int r, int c){
    vector<pair<int, int>> neighbor;
    if(r-1>=0 && !visited[r-1][c]){
        neighbor.emplace_back(r-1, c);
    }
    if(r+1<m && !visited[r+1][c]){
        neighbor.emplace_back(r+1, c);
    }
    if(c-1>=0 && !visited[r][c-1]){
        neighbor.emplace_back(r, c-1);
    }
    if(c+1<n && !visited[r][c+1]){
        neighbor.emplace_back(r, c+1);
    }
    return neighbor;
}

bool dfs(vector<vector<bool>>& visited, int r, int c){
    visited[r][c] = true;
    cur++;
    auto neighbor = findNeighbor(visited, r, c);
    if(flag && (r==0 || c==0 || r==m-1 || c==n-1)) flag = false;
    for(auto& pos: neighbor){
        if(!visited[pos.first][pos.second]) dfs(visited, pos.first, pos.second);
    }

    return true;
}


int numEnclaves(vector<vector<int>>& grid) {
    vector<int> tmp;
    m = (int)grid.size();
    n = (int)grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, true));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j]) visited[i][j] = false;
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(!visited[i][j]){
                cur=0;
                flag = true;
                dfs(visited, i, j);
                if(flag){
                    cnt+=cur;
                }
            }

        }
    }
    return cnt;
}


int main() {

    vector<vector<int>> grid {{0,0,0,1,1,1,0,1,1,1,1,1,0,0,0},
                              {1,1,1,1,0,0,0,1,1,0,0,0,1,1,1},
                              {1,1,1,0,0,1,0,1,1,1,0,0,0,1,1},
                              {1,1,0,1,0,1,1,0,0,0,1,1,0,1,0},
                              {1,1,1,1,0,0,0,1,1,1,0,0,0,1,1},
                              {1,0,1,1,0,0,1,1,1,1,1,1,0,0,0},
                              {0,1,0,0,1,1,1,1,0,0,1,1,1,0,0},
                              {0,0,1,0,0,0,0,1,1,0,0,1,0,0,0},
                              {1,0,1,0,0,1,0,0,0,0,0,0,1,0,1},
                              {1,1,1,0,1,0,1,0,1,1,1,0,0,1,0}};
    cout << numEnclaves(grid);
    return 0;
}
