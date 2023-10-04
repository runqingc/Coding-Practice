#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int cnt = 0;
        deque<int> q{0};
        visited[0] = true;
        while(!q.empty()){
            int room = q.front();
            ++cnt;
            q.pop_front();
            for(auto& i: rooms[room]){
                if(!visited[i]){
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
        return cnt == rooms.size();
    }
};



int main() {

    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    Solution solution;
    cout << solution.canVisitAllRooms(rooms);

    return 0;
}
