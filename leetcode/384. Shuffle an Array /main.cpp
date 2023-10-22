#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int>& nums):origin(nums) {
    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        // 从1到n之间随机出一个数和最后一个数(n)交换，然后从1到n-1之间随机出一个数和倒数第二个数(n-1)交换...
        // 使用随机设备来种子
        std::random_device rd;
        // 使用 mt19937 作为随机数生成器
        std::mt19937 gen(rd());
        vector<int> copy(origin);
        for(int i=(int)origin.size()-1; i>=0; --i){
            // 使用均匀分布，生成 [0, i] 之间的随机整数
            std::uniform_int_distribution<> distrib(0, i);
            swap(copy[i], copy[distrib(gen)]);
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main() {
    cout << RAND_MAX;

    return 0;
}
