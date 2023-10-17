#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> uset;
    uset.reserve(nums.size());
    for(int i=1; i<=nums.size(); ++i){
        uset.insert(i);
    }
    for(auto& num:nums){
        uset.erase(num);
    }
    vector<int> ans;
    ans.reserve(uset.size());
    for(auto& i:uset){
        ans.push_back(i);
    }
    return ans;
}





int main() {

    vector<int> nums = {1,1};
    auto ret = findDisappearedNumbers(nums);
    for(auto& i: ret){
        cout << i << " ";
    }

    return 0;
}
