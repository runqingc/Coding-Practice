#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0, j=numbers.size()-1;
    for( ; ;){
        if(numbers[i]+numbers[j]<target){
            i++;
        }else if(numbers[i]+numbers[j]>target){
            j--;
        }else{
            return vector<int>{i+1,j+1};
        }
    }
}

int main() {
    vector<int> numbers {2,7,11,15};
    vector<int> ans = twoSum(numbers, 9);
    std::cout << ans[0] <<" " << ans[1] << std::endl;
    return 0;
}
