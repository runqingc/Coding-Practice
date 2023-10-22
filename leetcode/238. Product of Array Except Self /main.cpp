#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int)(nums.size());
    vector<int>prefix(nums.size(), 1);
    vector<int>postfix(nums.size(), 1);
    for(int i=1; i<n; ++i){
        prefix[i] = prefix[i-1]*nums[i-1];
        postfix[n-1-i] = postfix[n-i]*nums[n-i];
    }
    vector<int> ans(n);
    for(int i=0; i<n; ++i){
        ans[i] = prefix[i]*postfix[i];
    }
    return ans;
}




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
