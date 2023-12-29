#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Compare
{
    bool operator()(int x, int y){
        return x<y;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0]<rhs[0];
        });

        // decide if there are available rooms
        priority_queue<int, vector<int>, greater<int>> q;

        q.push(-1);
        
        for(auto& interval: intervals){
            if(q.top()<=interval[0]){
                q.pop();
                q.push(interval[1]);
            }else{
                q.push(interval[1]);
            }
        }

        return q.size();
    }
};


int main(){

    vector<vector<int>> intervals {{0,30},{5,10},{15,20}};
    Solution s;
    cout << s.minMeetingRooms(intervals);

    return 0;
}