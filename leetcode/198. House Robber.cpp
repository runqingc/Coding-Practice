#include<vector>
using namespace std;

class Solution {
public:
    int max(int a, int b){
        if(a>=b) return a;
        else return b;
    }

    int rob(vector<int>& nums) {
        int pre0 = 0;
        int n = nums.size();
        int pre1  = nums[0];
        if(n==1) return pre1;
        int pre2 = max(nums[1], nums[0]);
        if(n==2) return pre2;
        int pre3 = max(nums[0] + nums[2], nums[1]);
        if(n==3) return pre3;


        int result = 0;
        for(int i=3; i<=n; i++){
            result = max(nums[i-1]+pre2, nums[i-2]+pre0);
            pre3 = result;
            pre2 = pre3;
            pre1 = pre2;
            pre0 = pre1;
        }

        return result;
    }
};