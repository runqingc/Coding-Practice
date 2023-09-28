#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> umap;
    int cnt = 0;
    for(auto& i: nums1){
        for(auto& j: nums2){
            if(umap.find(i+j)==umap.end()){
                umap[i+j] = 1;
            }else{
                ++umap[i+j];
            }
        }
    }
    for(auto& i: nums3){
        for(auto& j: nums4){
            if(umap.find(-i-j)!=umap.end()){
                cnt += umap[-i-j];
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> nums1 = {1,2}, nums2 = {-2,-1}, nums3 = {-1,2}, nums4 = {0,2};
    std::cout << fourSumCount(nums1, nums2, nums3, nums4) << std::endl;
    return 0;
}
