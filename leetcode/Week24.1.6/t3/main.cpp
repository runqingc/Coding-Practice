#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()/2;
        unordered_map<int, int> umap1;
        unordered_map<int, int> umap2;
        for(auto num: nums1){
            if(umap1.find(num)==umap1.end()){
                umap1[num] = 1;
            }else{
                ++umap1[num];
            }
        }
        for(auto num: nums2){
            if(umap2.find(num)==umap2.end()){
                umap2[num] = 1;
            }else{
                ++umap2[num];
            }
        }
        int u1dup = 2*n-umap1.size();
        int u2dup = 2*n-umap2.size();
        int common = 0;
        int u1uni = 0;
        int u2uni = 0;
        for(auto& pair: umap1){
            if(umap2.find(pair.first)!=umap2.end()){
                ++common;
            }else{
                ++u1uni;
            }
        }
        u2uni = umap2.size()-common;
        int ans = 0;
        if(u1uni>=n){
            ans+= n;
            ans += min(n, common+u2uni);
        }else{
            ans += u1uni;
            int temp = min(common, n-u1uni);
            ans += temp;
            common -= temp;
            ans += min(n, common+u2uni);
            
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> n1{1,2,3,4,5,6};
    vector<int> n2{2,3,2,3,2,3};
    cout << s.maximumSetSize(n1, n2);

    
    return 0;
}