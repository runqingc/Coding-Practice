#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLHS(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> hash;
    for(auto num: nums){
        ++hash[num];
    }
    for(auto& [key, cnt]: hash){
        if(hash.find(key-1)!=hash.end() && cnt+hash[key-1]>ans){
            ans = cnt+hash[key-1];
        }
        if(hash.find(key+1)!=hash.end() && cnt+hash[key+1]>ans){
            ans = cnt+hash[key+1];
        }
    }

    return ans;
}



int main() {
    vector<int> nums{2,4,6,8};
    std::cout << findLHS(nums) << std::endl;
    return 0;
}
