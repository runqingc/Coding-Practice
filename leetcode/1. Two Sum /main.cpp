#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for(int i=0; i<nums.size(); ++i){
        if(umap.find(target-nums[i])!=umap.end()){
            return vector<int>{umap[target-nums[i]],i};
        }
        if(umap.find(nums[i])==umap.end()){
            umap[nums[i]] = i;
        }else{
            if(nums[i]*2==target){
                return vector<int>{umap[nums[i]],i};
            }
        }
    }
    return vector<int>{0,1};
}

int main() {
    vector<int> nums{2,7,11,15};
    vector<int> ans = twoSum(nums, 9);
    return 0;
}
