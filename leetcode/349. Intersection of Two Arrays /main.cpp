#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    unordered_set<int> set;
    vector<int> ans;
    for(auto& i: nums1){
        set.insert(i);
    }
    for(auto& i: nums2){
        if(set.find(i)!=set.end()){
            ans.push_back(i);
        }
    }

    return ans;
}


int main() {
    vector<int> v1{1,2,3,3,4,5};
    vector<int> v2{2,3,2,6,7,1};
    auto ans = intersection(v1, v2);
    return 0;
}
