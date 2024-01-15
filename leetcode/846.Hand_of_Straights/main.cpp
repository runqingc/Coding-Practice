#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize==1) return true;
        if(hand.size()%groupSize!=0) return false;
        int numGroup = hand.size()/groupSize;
        std::sort(hand.begin(), hand.end());
        deque<vector<int>> q;
        for(auto& card: hand){
            if(q.empty()){
                q.push_back(vector<int>{card});
                --numGroup;
                if(numGroup<0) return false;
            }else{
                int i=0;
                bool flag = false;
                for( ; i<q.size(); ++i){
                    if(q[i].back()+1==card){
                        q[i].push_back(card);
                        flag = true;
                        if(q[0].size()==groupSize) q.pop_front();
                        break;
                    }else if(q[i].back()+1<card){
                        return false;
                    }
                }
                if(!flag){
                    q.push_back(vector<int>{card});
                    --numGroup;
                    if(numGroup<0) return false;
                }
            }
        }
        return true;
    }
};


int main(){

    vector<int> hand{5,1};
    int groupSize = 1;
    Solution s;
    cout << s.isNStraightHand(hand, groupSize);

    return 0;
}