#include <iostream>
#include <vector>
#include <queue>
using namespace std;


#define INF INT32_MAX

class Solution {
    int distance = 1;
public:
    // multiple source BFS
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = (int)rooms.size();
        int n = (int)rooms[0].size();
        queue<pair<int, int>> q;
        // enqueue all the gates
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(rooms[i][j]==0){
                    q.emplace(i, j);
                }
            }
        }
        // bfs
        auto is_valid = [this, &rooms, m, n](int i, int j)mutable{
            if(i>=0 && i<m && j>=0 && j<n && rooms[i][j]==INF){
                rooms[i][j] = distance;
                return true;
            }
            return false;
        };
        while(!q.empty()){
            int num = q.size();
            while(num--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                //enqueue it's adjacent tiles
                if(is_valid(i+1, j)) q.emplace(i+1,j);
                if(is_valid(i-1, j)) q.emplace(i-1,j);
                if(is_valid(i, j+1)) q.emplace(i,j+1);
                if(is_valid(i, j-1)) q.emplace(i,j-1);
            }
            ++distance;
        }
    }
};


int main(){

    cout << INF << endl;
    Solution solution;
    vector<vector<int>> rooms {{2147483647,-1,0,2147483647},
    {2147483647,2147483647,2147483647,-1},
    {2147483647,-1,2147483647,-1},
    {0,-1,2147483647,2147483647}};
    solution.wallsAndGates(rooms);

    for(auto& i : rooms){
        for(auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}