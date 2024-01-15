#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        queue<pair<int, int>> q;
        int time = -1;
        int fresh = 0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==2){
                    q.emplace(i,j);
                }else if(grid[i][j]==1){
                    ++fresh;
                }
            }
        }
        auto enqueue = [m, n, &grid, &q, &fresh](int i, int j){
            if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1){
                grid[i][j] = 2;
                q.emplace(i, j);
                --fresh;
            } 
        };
        while(!q.empty()){
            ++time;
            int num = q.size();
            while(num--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                // enqueue all adjacent oranges
                enqueue(i+1, j);
                enqueue(i-1, j);
                enqueue(i, j+1);
                enqueue(i, j-1);
            }
        }
        return (fresh==0)?(time):(-1);
    }
};



int main(){



    return 0;
}


