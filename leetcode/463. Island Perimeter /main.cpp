#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    int parameter=0;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j]==1){
                if(i-1<0 || grid[i-1][j]==0){
                    ++parameter;
                }
                if(i+1>=m || grid[i+1][j]==0){
                    ++parameter;
                }
                if(j-1<0 || grid[i][j-1]==0){
                    ++parameter;
                }
                if(j+1>=n || grid[i][j+1]==0){
                    ++parameter;
                }
            }
        }
    }
    return parameter;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
