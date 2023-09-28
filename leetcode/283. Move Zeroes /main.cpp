#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    for( ; fast<nums.size(); ++fast){
        if(nums[fast]!=0){
            nums[slow] = nums[fast];
            ++slow;
        }
    }
    for( ; slow<nums.size(); ++slow){
        nums[slow] = 0;
    }
}


int main() {

    return 0;
}
