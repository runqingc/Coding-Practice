#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::make_heap(stones.begin(), stones.end());
        while(stones.size()>1){
            int stone1 = stones.front();
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int stone2 = stones.front();
            std::pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if(stone1>stone2){
                stones.push_back(stone1-stone2);
                push_heap(stones.begin(), stones.end());
            }
        }
        return (stones.empty())?(0):(stones.front());
    }
};








int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
