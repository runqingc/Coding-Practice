#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int minStep = 0;
        int maxDistance;
        int nextGrid=0;
        for(int i=0; i<nums.size(); i = nextGrid){
            maxDistance = i+nums[i];
            ++ minStep;
            if(maxDistance>=nums.size()-1){
                return minStep;
            }
            int max = 0;
            for(int j = i; j<=maxDistance; ++j){
                if(j+nums[j]>max){
                    max = j+nums[j];
                    nextGrid = j;
                }
            }
        }

        return minStep;
    }
};



int main() {
    vector<int> nums{2};
    Solution s1;
    cout << s1.jump(nums);

    return 0;
}
