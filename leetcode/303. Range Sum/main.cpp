#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> data;
    vector<int> prefix;
public:
    NumArray(vector<int>& nums):data(nums) {
        prefix.reserve(nums.size());
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); ++i){
            prefix[i] = prefix[i-1]+nums[i];
        }
    }

    int sumRange(int left, int right) {
        return (left==0)?(prefix[right]):(prefix[right]-prefix[left-1]);
    }
};

int main() {

    return 0;
}
