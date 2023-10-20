#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int minMoves2(vector<int>& nums) {
    if(nums.size()==1) return 0;
    if(nums.size()==2) return abs(nums[1]-nums[0]);
    std::sort(nums.begin(), nums.end());
    int mid = nums.size()/2;
    while(true){
        //try move left
        if(-mid*(nums[mid]-nums[mid-1])+(nums.size()-mid)*(nums[mid]-nums[mid-1])<0){
            --mid;
        }
        // try move left
        else if((mid+1)*(nums[mid+1]-nums[mid])-(nums.size()-1-mid)*(nums[mid+1]-nums[mid])<0){
            ++mid;
        }else {
            break;
        }
    }
    int move = 0;
    for(auto num: nums){
        move += abs(num-nums[mid]);
    }
    return move;
}


int main() {
    vector<int> nums{1,2};
    cout << minMoves2(nums);
    return 0;
}
