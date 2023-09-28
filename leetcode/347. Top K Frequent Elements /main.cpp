#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct table{
    int val;
    int frequency = 0;
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<struct table> troll;
    for(int i=-10000; i<=10020; i++){
        troll.push_back(table{i, 0});
    }
    for(int num : nums){
        troll[num+10000].frequency++;
    }
    sort(troll.begin(), troll.end(), [&](const struct table& a, const struct table& b)->bool{
        return a.frequency>b.frequency;
    });
    vector<int> ans;
    for(int i=0; i<k; i++){
        ans.push_back(troll[i].val);
    }
    return ans;
}

int main() {
    vector<int> nums{1,1,1,2,2,3};
    vector<int> ans = topKFrequent(nums, 2);
    for(auto& i: ans)
     std::cout << i<< std::endl;
    return 0;
}
