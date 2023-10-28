#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int cnt = 0, prefix=0;
    unordered_map<int, int> umap;
    umap[0] = 1;
    for(auto i: nums){
        prefix+=i;
        cnt += umap[prefix-k];
        ++umap[prefix];
    }
    return cnt;
}



int main() {
    vector<int> nums{1};

    cout << subarraySum(nums, 0) << endl;
    return 0;
}
