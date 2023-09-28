#include <iostream>
#include <vector>
using namespace std;

int calWiggle(vector<int>& nums, bool isUp){
    int len = 1;
    int last = nums[0];
    for(auto& i: nums){
        if(isUp){
            if(i>last){
                last = i;
                ++len;
                isUp = false;
            }else if(i<last){
                last = i;
            }
        }else{
            if(i<last){
                last = i;
                ++len;
                isUp = true;
            }else if(i>last){
                last = i;
            }
        }
    }
    return len;
}

int wiggleMaxLength(vector<int>& nums) {
    return max(calWiggle(nums, true), calWiggle(nums, false));
}


int main() {
    vector<int> nums{1,7,4,9,2,5};
    std::cout << wiggleMaxLength(nums) << std::endl;
    return 0;
}
