#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int missingNumber(vector<int>& nums) {
    long long ans = 0;
    for(auto num : nums){
        ans ^= num;
    }
    for(int i=0; i<=nums.size(); ++i){
        ans^=i;
    }
    return ans;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
