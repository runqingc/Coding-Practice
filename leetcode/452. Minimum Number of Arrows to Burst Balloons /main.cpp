#include <iostream>
#include <vector>
using namespace std;

// shoot at "last_end" ?
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int> b)->bool{
        return a[1]<b[1];
    });
    int last_end = points[0][1]; int cnt = 1;
    for(int i=1; i<points.size(); i++){
        if(points[i][0]>last_end){
            last_end = points[i][1]; cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    std::cout <<  findMinArrowShots(points) << std::endl;
    return 0;
}
