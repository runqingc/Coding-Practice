#include <iostream>
#include <vector>
using namespace std;


int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(1, nums[0]);
    for(auto& i: nums){
        if(i>dp.back()){
            dp.push_back(i);
        }else{
            // find the first character >= i
            *(lower_bound(dp.begin(), dp.end(), i)) = i;
        }
    }
    return (int)(dp.size());
}


int main() {
    vector<int> nums {3,5,6,2,5,4,19,5,6,7,12};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
