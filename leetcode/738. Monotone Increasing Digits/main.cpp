#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string s = to_string(n);

        // check if there's nums[i]<nums[i-1]
        for(int i=1; i<s.size(); ++i){

            if(s[i]<s[i-1]){
                // set all digits behind i to 9
                for(int j=i; j<s.size(); ++j){
                    s[j] = '9';
                }
                --s[i-1];
                for(int j = i-2; j>=0; --j){
                    if(s[j]>s[j+1]){
                        --s[j];
                        s[j+1] = '9';
                    }
                }
                return stoi(s);
            }

        }
        return n;


    }
};




int main() {
    Solution s1;
    cout << s1.monotoneIncreasingDigits(98);
    return 0;
}
