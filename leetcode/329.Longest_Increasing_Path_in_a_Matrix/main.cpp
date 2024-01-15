#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(int i, int j):x(i),y(j){}
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxDistance = 1;
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        vector<int> off_i = {1,-1,0,0};
        vector<int> off_j = {0,0,1,-1};
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        vector<vector<int>> path(m, vector<int>(n, 1));
        queue<Point> q;
        auto valid = [m, n](int i, int j){return i>=0 && j>=0 && i<m && j<n;};

        // calculate indegree
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(valid(i+1, j) && matrix[i+1][j]<matrix[i][j]) ++indegree[i][j];
                if(valid(i-1, j) && matrix[i-1][j]<matrix[i][j]) ++indegree[i][j];
                if(valid(i, j+1) && matrix[i][j+1]<matrix[i][j]) ++indegree[i][j];
                if(valid(i, j-1) && matrix[i][j-1]<matrix[i][j]) ++indegree[i][j];
                if(indegree[i][j]==0)q.emplace(i,j);
            }
        }

        while(!q.empty()){
            int i = q.front().x;
            int j = q.front().y;
            q.pop();
            for(int k=0; k<4; ++k){
                int adj_i = i+off_i[k];
                int adj_j = j+off_j[k];
                if(valid(adj_i, adj_j) && matrix[adj_i][adj_j]>matrix[i][j]){
                    if(--indegree[adj_i][adj_j]==0){
                        path[adj_i][adj_j] = path[i][j]+1;
                        maxDistance = max(maxDistance, path[adj_i][adj_j]);
                        q.emplace(adj_i, adj_j);
                    }
                }
            }
        }
        return maxDistance;
    }
};
// for(int l=0; l<4; ++l){
                        //     if(valid(adj_i+off_i[l], adj_j+off_j[l]) && matrix[adj_i+off_i[l]][adj_j+off_j[l]]<matrix[adj_i][adj_j]){
                        //         path[adj_i][adj_j] = max(path[adj_i][adj_j], path[adj_i+off_i[l]][adj_j+off_j[l]])+1;
                        //         maxDistance = max(maxDistance, path[adj_i][adj_j]);
                        //     }
                        // }

int main(){

    vector<vector<int>> matrix{{3,4,5}, {3,2,6}, {2,2,1}};
    Solution s;
    cout << s.longestIncreasingPath(matrix);

    return 0;
}