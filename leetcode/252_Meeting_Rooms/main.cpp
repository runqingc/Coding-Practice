#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>&rhs){
            return lhs[0]<rhs[0];
        });
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i-1][1]>intervals[i][0]){
                return false;
            }
        }
        return true;
    }
};



int main(){

    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    Solution s;
    cout << s.canAttendMeetings(intervals);

    return 0;
}