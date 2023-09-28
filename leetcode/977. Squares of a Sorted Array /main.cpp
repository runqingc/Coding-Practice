#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for(int i=0; i<nums.size(); ++i){
        nums[i] = i*i;
    }

    sort(nums.begin(), nums.end());
    return nums;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
