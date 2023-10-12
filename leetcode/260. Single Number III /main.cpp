#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


vector<int> singleNumber(vector<int>& nums) {
    unordered_set<int> set;
    for(auto& num: nums){
        if(set.find(num)==set.end()){
            set.insert(num);
        }else{
            set.erase(num);
        }
    }
    vector<int> ret;
    ret.reserve(set.size());
    for(int i : set){
        ret.push_back(i);
    }
    return ret;
}


int main() {
    vector<int> nums = {1,2,1,3,2,5};
    auto ans = singleNumber(nums);
    for(auto& i: ans){
        cout << i;
    }
    return 0;
}
