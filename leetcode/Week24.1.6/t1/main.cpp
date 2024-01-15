#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        sort(dimensions.begin(), dimensions.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0]*a[0]+a[1]*a[1]>b[0]*b[0]+b[1]*b[1]) || ((a[0]*a[0]+a[1]*a[1]==b[0]*b[0]+b[1]*b[1]) && a[0]*a[1]>b[0]*b[1]);
        });
        return dimensions[0][0]*dimensions[0][1];
    }
};

int main(){

    Solution s;
    vector<vector<int>> d{{9,3}, {8,6}};
    cout << s.areaOfMaxDiagonal(d);

    return 0;
}