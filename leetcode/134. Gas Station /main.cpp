#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1) return (gas[0]>=cost[0])?0:-1;
        if(gas.size()==1) return 0;
        int size = (int) gas.size();
        for(int i=0; i<size; ++i){
            gas[i] -= cost[i];
        }

        int curBalance = 0;
        int start = 0;
        for(int i=0; ; ++i){
            if(i-start==size) return start;
            curBalance += gas[i%size];
            if(curBalance<0){
                curBalance = 0;
                start = i+1;
                if(start>=size) return -1;
            }

        }
        return start;
    }
};



int main() {
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    Solution s1;
    cout << s1.canCompleteCircuit(gas, cost);

    return 0;
}
