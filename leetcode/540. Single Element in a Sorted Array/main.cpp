#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = (int)(nums.size()-1), mid;
    // handle special case: single element in the front or end;
    // or, size == 1
    if(nums.size()==1) return nums[0];
    if(nums[l]!=nums[l+1]) return nums[l];
    if(nums[r]!=nums[r-1]) return nums[r];
    while(l<=r){
        mid = (l+r)/2;
        if(mid!=0 && mid!=nums.size()-1 && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
            return nums[mid];
        }else if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return nums[mid];
}


int main() {
    vector<int> nums{1,1,2,3,3,4,4,8,8};
    std::cout << singleNonDuplicate(nums) << std::endl;
    return 0;
}
