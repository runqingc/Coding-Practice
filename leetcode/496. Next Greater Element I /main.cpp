#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> umap;
    stack<int> s;
    vector<int> ans(nums1.size(), -1);
    vector<int> greater(nums2.size(), 0);
    for(int i=0; i<nums2.size(); ++i){
        umap[nums2[i]] = i;
    }
    for(int i=0; i<nums2.size(); ++i){
        if(s.empty()){
            s.push(i);
        }else{
            while(!s.empty() && nums2[s.top()]<nums2[i]){
                greater[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    for(int i=0; i<nums1.size(); ++i){
        if(greater[umap[nums1[i]]]!=0){
            ans[i] = nums2[greater[umap[nums1[i]]]];
        }
    }
    return ans;
}


int main() {
    vector<int> nums1{4,1,2};
    vector<int> nums2{1,3,4,2};
    auto ans = nextGreaterElement(nums1, nums2);
    for(auto& i: ans){
        cout << i << " ";
    }

    return 0;
}
