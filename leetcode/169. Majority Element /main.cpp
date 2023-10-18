#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int majority = nums[0];
    int cnt = 1;
    for(int i=1; i<nums.size(); ++i){
        if(nums[i]==majority){
            ++cnt;
        }else{
            --cnt;
            if(cnt==0){
                majority = nums[i];
                cnt = 1;
            }
        }
    }
    return majority;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
