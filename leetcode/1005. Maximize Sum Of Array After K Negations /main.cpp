#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    int sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap(nums.begin(), nums.end());
    for(int i=0; i<k; ++i){
        int tmp = minHeap.top();
        minHeap.pop();
        minHeap.push(-tmp);
    }
    while (!minHeap.empty()){
        sum+=minHeap.top();
        minHeap.pop();
    }
    return sum;
}


int main() {
    vector<int> nums{3,-1,0,2};
    cout << largestSumAfterKNegations(nums, 3);
    return 0;
}
