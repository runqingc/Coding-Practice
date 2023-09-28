#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int max_dis = 0;
        for(int i=0; i<=max_dis; ++i){
            if(i+nums[i]>max_dis){
                max_dis = i+nums[i];
                if(max_dis>=nums.size()-1){
                    return true;
                }
            }
        }
        return false;
    }
};



int main() {
    vector<int> nums{3,2,1,0,4};
    Solution s1;
    cout << s1.canJump(nums);
    return 0;
}
