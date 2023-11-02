#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// move the shorter board inner

int maxArea(vector<int>& height) {
    int max_water = 0;

    auto i = height.begin(), j = height.end()-1;

    while(i<j){
        max_water = max(max_water, (int)(j-i)*(min(*i, *j)));
        if(*i<*j){
            ++i;
        }else{
            --j;
        }
    }

    return max_water;
}
int main() {
    vector<int> nums {1,0,0,0,0,0,0,2,2};
    std::cout << maxArea(nums) << std::endl;
    return 0;
}
