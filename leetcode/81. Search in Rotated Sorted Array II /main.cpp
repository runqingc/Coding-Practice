#include <iostream>
#include <vector>
using namespace std;

// can not be done in O(log N) ?
// compare nums[mid] with nums[r]
// case1: nums[mid] > nums[r]
// case2: nums[mid] < nums[r]  right part sorted
// case3: nums[mid] == nums[r]
bool search(vector<int>& nums, int target) {
    int l = 0, r = (int)(nums.size()-1); int mid;
    while(l<=r){
        mid = (l+r)/2;
        if(nums[mid]==target){
            return true;
        }else if(nums[mid] == nums[r]){
            if(nums[l]==target) return true;
            else l++;
        }else if(nums[mid] < nums[r]){ // right part sorted
            //search target in the sorted part
            int tmp_l = mid+1; int tmp_r = r;
            while(tmp_l<=tmp_r){
                mid = (tmp_l+tmp_r)/2;
                if(nums[mid]==target){
                    return true;
                }else if(nums[mid]>target){
                    tmp_r = mid-1;
                }else{
                    tmp_l = mid+1;
                }
            }
            // not found in the sorted part, search in the rotated part
            r = mid-1;
        }else{ // left part sorted
            //search target in the sorted part
            int tmp_l = l; int tmp_r = mid-1;
            while(tmp_l<=tmp_r){
                mid = (tmp_l+tmp_r)/2;
                if(nums[mid]==target){
                    return true;
                }else if(nums[mid]>target){
                    tmp_r = mid-1;
                }else{
                    tmp_l = mid+1;
                }
            }
            // not found in the sorted part, search in the rotated part
            l = mid+1;
        }
    }
    return false;
}

int main() {
    int target = 0;
    vector<int> nums {1,0,1,1,1};
    cout << search(nums, target) << endl;
    return 0;
}
