#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// activity selection problem
int findLongestChain(vector<vector<int>>& pairs) {
    // sort the activity according to their end time
    sort(pairs.begin(), pairs.end(), [&](const vector<int>& a, const vector<int>& b)->bool{
        return a.back()<b.back();
    });
    int last_end = pairs[0][1];
    int cnt = 1;
    for(auto& i: pairs){
        if(i.front()>last_end){
            last_end = i.back();
            ++cnt;
        }
    }
    return cnt;
}



int main() {
    vector<vector<int>> pairs {{1,2}, {7,8}, {4,5}};
    cout << findLongestChain(pairs);
    return 0;
}
