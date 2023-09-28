#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2, 0);

        for(auto& i: bills){
            if(i==5){
                ++change[0];
            }else if(i==10){
                if(change[0]>=1){
                    --change[0];
                    ++change[1];
                }else{
                    return false;
                }
            }else{
                if(change[0]>=1 && change[1]>=1){
                    --change[0];
                    --change[1];
                }else if(change[0]>=3){
                    change[0] -=3;
                }else{
                    return false;
                }

            }
        }
        return true;
    }
};

int main() {
    Solution s1;
    vector<int> bills{5,5,10,10,20};

    cout << s1.lemonadeChange(bills);

    return 0;
}
