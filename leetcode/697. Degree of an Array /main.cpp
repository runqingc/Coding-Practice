#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findShortestSubArray(vector<int>& nums) {

    vector<int> max_element;
    int max_sum = 0;
    unordered_map<int, int> cnt;
    unordered_map<int, int> firstOccurrence;
    unordered_map<int, int> lastOccurrence;

    for(int i=0; i<nums.size(); ++i){
        if(firstOccurrence.find(nums[i])==cnt.end()){
            firstOccurrence[nums[i]] = i;
        }
        ++cnt[nums[i]];
        if(cnt[nums[i]]>max_sum){
            max_element.clear();
            max_element.push_back(nums[i]);
            max_sum = cnt[nums[i]];
        }else if(cnt[nums[i]]==max_sum){
            max_element.push_back(nums[i]);
        }

    }

    for(int i=(int)nums.size()-1; i>=0; --i){
        if(lastOccurrence.find(nums[i])==cnt.end()){
            lastOccurrence[nums[i]] = i;
        }
    }

    int min_length = INT32_MAX;
    for(auto i: max_element){
        if(lastOccurrence[i]-firstOccurrence[i]+1<min_length){
            min_length = lastOccurrence[i]-firstOccurrence[i]+1;
        }
    }

    return min_length;
}




int main() {
    vector<int> nums{1,2,2,3,1,4,2};
    std::cout << findShortestSubArray(nums)<< std::endl;
    return 0;
}
