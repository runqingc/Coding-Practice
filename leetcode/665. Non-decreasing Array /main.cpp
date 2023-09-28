#include <iostream>
#include <vector>
using namespace std;

bool checkIncrease(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}

bool checkPossibility(vector<int>& nums) {
    for(int i=1; i<nums.size(); i++){
        if(nums[i]<nums[i-1]){
            int tmp = nums[i];
            // remedy1: remove nums[i] and check if the rest of the arr is increasing
            nums[i] = nums[i-1];
            if(checkIncrease(nums)) return true;
            else{
                nums[i] = tmp;
                nums[i-1] = nums[i];
                // remedy2: remove nums[i-1] and check if the rest of the arr is increasing
                if(checkIncrease(nums)) return true;
                else return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> nums{0,1,2,1,2,2,1};
    std::cout << checkPossibility(nums) << std::endl;
    return 0;
}
