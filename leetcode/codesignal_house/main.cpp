#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    unordered_set<int> uset;
    for(auto num: nums){
        if(uset.find(num)==uset.end()){
            uset.insert(num);
        }else{
            return num;
        }
    }
    return 0;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
