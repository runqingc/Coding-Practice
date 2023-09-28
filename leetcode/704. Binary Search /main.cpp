#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int l=0, r = (int)nums.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums{5};
    cout << search(nums, 5) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
