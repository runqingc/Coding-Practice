#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int& this_area){
    ++this_area;
    visited[r][c] = 1;
    if(r-1>=0 && grid[r-1][c]==1 && visited[r-1][c]==0){
        dfs(grid, visited, r-1, c, this_area);
    }
    if(r+1<grid.size() && grid[r+1][c]==1 && visited[r+1][c]==0){
        dfs(grid, visited, r+1, c, this_area);
    }
    if(c-1>=0 && grid[r][c-1]==1 && visited[r][c-1]==0){
        dfs(grid, visited, r, c-1, this_area);
    }
    if(c+1<grid[0].size() && grid[r][c+1]==1 && visited[r][c+1]==0){
        dfs(grid, visited, r, c+1,this_area);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0, this_area = 0;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    for(int r=0; r<grid.size(); ++r){
        for(int c=0; c<grid[0].size(); ++c){
            if(grid[r][c] && visited[r][c]==0){
                this_area = 0;
                dfs(grid, visited, r, c, this_area);
                if(this_area>max_area){
                    max_area = this_area;
                }
            }
        }
    }

    return max_area;
}

int main() {
    vector<vector<int>>grid {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    std::cout << maxAreaOfIsland(grid) << std::endl;
    return 0;
}
