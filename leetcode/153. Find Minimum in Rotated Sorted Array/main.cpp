#include <iostream>
#include <vector>
using namespace std;


// compare nums[mid] with nums[r]
// case1: nums[mid] > nums[r]
// case2: nums[mid] < nums[r]  right part sorted
int findMin(vector<int>& nums) {
    int size = (int) nums.size();
    int l = 0; int r = size-1; int mid;
    while(l<=r){
        mid = (l+r)/2;
        if(nums[mid]<nums[(mid-1+size)%size] && nums[mid]<nums[(mid+1)%size]){
            return nums[mid];
        }else if(nums[mid]<nums[r]){ //right part sorted
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return nums[mid];
}


int main() {
    vector<int> nums{4,5,6,7,0,1,2};
    std::cout << findMin(nums) << std::endl;
    return 0;
}
