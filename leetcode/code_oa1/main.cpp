#include <iostream>
#include <vector>
using namespace std;

#define MAXN 30000
// lamp
vector<int> numLamp(vector<vector<int>>& lamps, vector<int>& points){

    vector<int> road(MAXN, 0);
    for(auto& lamp: lamps){
        ++road[lamp[0]];
        --road[lamp[1]+1];
    }




}


int main() {
    vector<vector<int>> lamps{{5,7}, {6,8}, {9,15}, {16,18}};
    vector<int> points{1,3,9,19,4,9,29};


    return 0;
}
