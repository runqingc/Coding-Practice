#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& visited){
    visited[r][c] = 1;
    if(r-1>=0 && visited[r-1][c]==0 && heights[r-1][c]>=heights[r][c]){
        dfs(r-1, c, heights, visited);
    }
    if(r+1<heights.size() && visited[r+1][c]==0 && heights[r+1][c]>=heights[r][c]){
        dfs(r+1, c, heights, visited);
    }
    if(c-1>=0 && visited[r][c-1]==0 && heights[r][c-1]>=heights[r][c]){
        dfs(r, c-1, heights, visited);
    }
    if(c+1<heights[0].size() && visited[r][c+1]==0 && heights[r][c+1]>=heights[r][c]){
        dfs(r, c+1, heights, visited);
    }
}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));
    vector<vector<int>> atlentic(heights.size(), vector<int>(heights[0].size(), 0));
    vector<vector<int>> ans;

    for(int r=0; r<heights.size(); ++r){
        if(pacific[r][0]==0){
            dfs(r, 0, heights, pacific);
        }
        if(atlentic[r][heights[0].size()-1]==0){
            dfs(r, heights[0].size()-1, heights, atlentic);
        }
    }
    for(int c=0; c<heights[0].size(); ++c){
        if(pacific[0][c]==0){
            dfs(0, c, heights, pacific);
        }
        if(atlentic[heights.size()-1][c]==0){
            dfs(heights.size()-1, c,heights, atlentic);
        }
    }

    for(int r=0; r<heights.size(); ++r){
        for(int c=0; c<heights[0].size(); ++c){
            if(pacific[r][c]==1 && atlentic[r][c]==1){
                ans.emplace_back(vector<int>{r, c});
            }
        }
    }

    return ans;
}

int main() {
//    vector<vector<int>> heights {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> heights {{2,1}, {1,2}};
    vector<vector<int>> ans = pacificAtlantic(heights);
    for(auto& i: ans){
        for(auto & j: i){
            cout << j ;
        }
        cout << endl;
    }
    return 0;
}
