#include <iostream>
#include <vector>
using namespace std;

// sliding window
// for every position of fast:
// if the current sum is not enough, move fast right
// if the current sum is enough, move slow right
int minSubArrayLen(int target, vector<int>& nums) {
    int fast=0, slow=0;
    int sum = 0; int cnt=INT_MAX;
    for( ;fast<nums.size(); ++fast){
        sum += nums[fast];
        if(sum>=target){
            while (slow+1<=fast && sum-nums[slow]>=target){
                sum -= nums[slow++];
            }
            if(fast-slow+1<cnt){
                cnt = fast-slow+1;
            }
        }
    }
    if(sum<target) return 0;
    return cnt;
}

int main() {
    vector<int> num {7};
    cout << minSubArrayLen(9, num);
    return 0;
}
