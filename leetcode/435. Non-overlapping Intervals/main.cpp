#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//sort activities according to their end time
//select one which ends earliest and do not conflict
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b)->bool{
        return a[1]<b[1];
    });
    int last_end = intervals[0][1]; int cnt = 0;
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0]<last_end){
            cnt++;
        }else{
            last_end = intervals[i][1];
        }
    }
    return cnt;
}


int main() {
    vector<vector<int>> intervals{{1,2}, {2,3}, {3,4}, {1,3}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
