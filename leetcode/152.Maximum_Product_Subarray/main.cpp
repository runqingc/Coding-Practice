#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int maxNum = INT32_MIN;
        int maxPos = 0;
        int maxNeg = 0;
        for(auto num: nums){
            if(num==0){
                maxPos = 0;
                maxNeg = 0;
            }else if(num>0){
                if(maxPos==0){
                    maxPos = num;
                    maxNeg *= num;
                }else{
                    maxPos *= num;
                    maxNeg *= num;
                }
            }else{
                if(maxNeg==0){
                    maxNeg = min(maxPos*num, num);
                    maxPos = 0;
                }else{
                    int maxPosCopy = maxPos;
                    maxPos = maxNeg*num;
                    maxNeg = min(maxPosCopy*num, num); 
                }
            }
            maxNum = max(maxNum, maxPos);
        }
        
        return maxNum;
    }
};


int main(){
    vector<int> nums {7,-2,-4};
    Solution s;
    cout << s.maxProduct(nums);

    return 0;
}
