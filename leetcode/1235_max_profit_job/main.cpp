#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;

struct TimeSlot{
    public:
    int start;
    int end;
    int profit;
    TimeSlot(int start, int end, int profit):start(start), end(end), profit(profit){}
};

struct Compare
{
    bool operator()(const TimeSlot& slot1, const TimeSlot& slot2) const{
        return slot1.end <= slot2.end;
    }
};


class Solution {
public:
    // sort according to end time
    // dp[i.end_time] the max profit can achieve at i-th job's end time
    // dp[i.end_time] = max(dp[i.start_time]+i.profit, dp[i-1.end_time])
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        set<TimeSlot, Compare> slots;
        map<int, int> maxProfit;
        for(int i=0; i<startTime.size(); ++i){
            slots.emplace(startTime[i], endTime[i], profit[i]);
        }
        int lastProfit = 0;
        for(auto& slot: slots){
            if(maxProfit.empty()){
                maxProfit[slot.end] = slot.profit;
            }else{
                // if not to do the job?
                auto it = maxProfit.lower_bound(slot.start);
                if(it==maxProfit.end() || (it->first>slot.start && it!=maxProfit.begin())){
                    --it;
                }else if(it->first>slot.start && it==maxProfit.begin()){
                    maxProfit[slot.end] = max(lastProfit, slot.profit); lastProfit = maxProfit[slot.end]; continue;
                }
                maxProfit[slot.end] = max(lastProfit, (it->first<=slot.start)?(it->second+slot.profit):(0));
            }
            lastProfit = maxProfit[slot.end];
        }

        return lastProfit;
    }
};


int main(){

    Solution s;
    vector<int> start{1,1,1};
    vector<int> end{2,3,4};
    vector<int> profit{5,6,4};
    
    cout << s.jobScheduling(start, end, profit);

    

    return 0;
}