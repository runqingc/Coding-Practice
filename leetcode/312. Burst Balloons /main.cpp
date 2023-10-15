#include <iostream>
#include <vector>
using namespace std;



int burst(vector<vector<int>>& memory, vector<int>& nums, int l, int r, int l_default, int r_default){

    if(r-l<=1){
        return 0;
    }else if(r-l==2){
        return l_default*nums[l+1]*r_default;
    }

    if(memory[l+1][r+1]!=-1){
        return memory[l+1][r+1];
    }

        int cur_max=0;
        for(int i=l+1; i<r; ++i){
            // i-th balloon will be burst last
            int this_sum = l_default*nums[i]*r_default;
            this_sum+= burst(memory, nums, l, i, l_default, nums[i]);
            this_sum+= burst(memory, nums, i, r, nums[i], r_default);
            if(this_sum>cur_max){
                cur_max = this_sum;
            }
        }
    memory[l+1][r+1]=cur_max;
    return cur_max;

}

int maxCoins(vector<int>& nums) {
    // memory[i][j] the max score one can get to burst balloons in (i, j), not inclusive on both ends
    vector<vector<int>> memory(nums.size()+2, vector<int>(nums.size()+2, -1));

    return burst(memory, nums, -1, (int)nums.size(), 1,1);
}


int main() {
    vector<int> nums{8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2,5};
    cout << maxCoins(nums);
    return 0;
}
