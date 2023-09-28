#include <iostream>
#include <vector>
using namespace std;

// find nums[i] such that nums[i]==target and nums[i-1]<target
int lower_bound(vector<int>& nums, int target){
    int l=0, r=nums.size()-1, mid;
    while(l<r){
        mid = (l+r)/2;
        if(nums[mid]==target && (mid==0 || nums[mid-1]<target)){
            return mid;
        }else if(nums[mid]>target ||
            (mid>0 && nums[mid]==target && nums[mid-1]>=target)||
                (mid==0 && nums[mid]>target)){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    if(l>r) return -1;
    return (nums[l]==target && (l==0 || nums[l-1]<target))?(l):(-1);
}

// find nums[i] such that nums[i]==target and nums[i+1]>target
int upper_bound(vector<int>& nums, int target){
    int l=0, r=nums.size()-1, mid;
    while(l<r){
        mid = (l+r)/2;
        if(nums[mid]==target && (mid==nums.size()-1 || nums[mid+1]>target)){
            return mid;
        }else if(nums[mid]<target ||
                 (mid<nums.size()-1 && nums[mid]==target && nums[mid+1]<=target)||
                (mid==nums.size()-1 && nums[mid]<target)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(l>r) return -1;
    return (nums[l]==target && (l==nums.size()-1 || nums[l+1]>target))?(l):(-1);
}


vector<int> searchRange(vector<int>& nums, int target) {
    return vector<int> {lower_bound(nums, target), upper_bound(nums, target)};
}

int main() {
    vector<int> nums{7,7,8,8,8,10,10, 10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    for(auto& i: ans){
        std::cout << i << " " << std::endl;
    }
    return 0;
}
