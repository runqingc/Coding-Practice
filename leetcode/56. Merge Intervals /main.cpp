#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](const vector<int>& a, const vector<int>& b)->bool {
            return a.front()<b.front();
        });

        vector<vector<int>> ans;
        vector<int> cur;
        for(auto& i: intervals){
            if(cur.empty()){
                cur.push_back(i.front());
                cur.push_back(i.back());
            }else{
                if(i.front()<=cur.back()){
                    if(i.back()>cur.back()){
                        cur.back() = i.back();
                    }
                }else{
                    ans.push_back(cur);
                    cur.clear();
                    cur.push_back(i.front());
                    cur.push_back(i.back());
                }
            }
        }
        if(!cur.empty()) ans.push_back(cur);
        return ans;
    }
};



int main() {

    Solution s1;
    
    vector<vector<int>> intervals {{8,10},{1,3},{15,18},{2,6}};
    vector<vector<int>> ret = s1.merge(intervals);
    for(auto& i: ret){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}
