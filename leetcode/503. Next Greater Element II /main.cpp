#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    for(int i=0; i<size; ++i){
        nums.push_back(nums[i]);
    }

    vector<int> ans(size, -1);
    deque<int> q;
    for(int i=0; i<nums.size(); ++i){
        if(q.empty()){
            q.push_back(i%size);
        } else{
            while(!q.empty() && nums[q.back()%size]<nums[i%size]){
                ans[q.back()%size] = nums[i%size];
                q.pop_back();
            }
            q.push_back(i%size);
        }
    }

    return ans;
}



int main() {
    vector<int> nums{1,2,3,2,1};
    auto ret = nextGreaterElements(nums);
    for(auto& i: ret){
        cout << i << " ";
    }

    return 0;
}
