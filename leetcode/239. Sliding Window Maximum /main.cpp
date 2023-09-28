#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans(nums.size()-k+1);
    list<int> m;
    int i, cnt = 0;
    for(i=0; i<k; ++i){
        if(m.empty()){
            m.push_back(i);
        }else if(nums[i]>nums[m.back()]){
            while(!m.empty() && nums[i]>nums[m.back()]){
                m.pop_back();
            }
            m.push_back(i);
        }else{
            m.push_back(i);
        }
    }
    ans[cnt++] = nums[m.front()];
    for( ; i<nums.size(); ++i){
        if(m.front()<i-k+1){
            m.pop_front();
        }
        if(m.empty()){
            m.push_back(i);
        }else if(nums[i]>nums[m.back()]){
            while(!m.empty() && nums[i]>nums[m.back()]){
                m.pop_back();
            }
            m.push_back(i);
        }else{
            m.push_back(i);
        }
        ans[cnt++] = nums[m.front()];
    }
    return ans;
}

int main() {
    vector<int> nums{1,3,1,2,0,5};
    vector<int> ans = maxSlidingWindow(nums, 3);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}
