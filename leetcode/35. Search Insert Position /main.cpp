#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    if(target>nums.back()) return (int)nums.size();
    if(target<nums.front()) return 0;
    int l=0, r = (int)nums.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid]==target || (mid>=1 && target<nums[mid] && target>nums[mid-1])){
            return mid;
        }else if(nums[mid]>target){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return 0;
}


int main() {
    vector<int> nums{1,3,5,6,8};
    cout << searchInsert(nums, 8) << endl;
    return 0;
}
