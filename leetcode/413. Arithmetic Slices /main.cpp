#include <iostream>
#include <vector>
using namespace std;


// dp[i] =
int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size()<3) return 0;
    int dp = 0;
    int this_incre;
    int last_incre = nums[1]-nums[0];
    int num_contiguous = 1;

    for(int i=2; i<nums.size(); ++i){
        this_incre = nums[i] - nums[i-1];
        if(this_incre==last_incre){
            ++num_contiguous;
            if(num_contiguous>=2){
                dp+=num_contiguous-1;
            }
        }else{
            num_contiguous = 1;
        }
        last_incre = this_incre;
    }
    return dp;
}


int main() {
    vector<int> nums{1,2,3,4,6,8,10};
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}
