#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1;
        int max = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>nums[i-1]){
                ++cnt;
                if(cnt>max){
                    max = cnt;
                }
            }else{
                cnt = 1;
            }
        }
        return max;
    }
};


int main() {
    Solution s1;
    vector<int> nums{1,3,5,4,7};
    cout << s1.findLengthOfLCIS(nums);

    return 0;
}
