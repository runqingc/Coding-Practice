#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int slow=1, fast=1;
    for( ; fast<nums.size(); ++fast){
        if(nums[fast]!=nums[fast-1]){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main() {
    vector<int> nums{1,1,2,2};
    cout << removeDuplicates(nums);
    return 0;
}
