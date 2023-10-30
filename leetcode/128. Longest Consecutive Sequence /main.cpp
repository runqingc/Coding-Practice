#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {

    int ans = 0;
    unordered_set<int> hash;
    for(auto num: nums){
        hash.insert(num);
    }

    for(auto num: nums){
        if(hash.find(num-1)==hash.end()){
            int cnt = 1;
            for(int i=num+1; hash.find(i)!=hash.end(); ++i){
                ++cnt;
            }
            if(cnt>ans){
                ans = cnt;
            }
        }
    }

    return ans;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
