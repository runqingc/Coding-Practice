#include <iostream>
#include <vector>
using namespace std;


int trap(vector<int>& height) {
    int rainwater = 0;
    vector<int> max_index;
    int max = -1;
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] > max) {
            max = height[i];
            max_index = {};
            max_index.push_back(i);
        }
    }

    vector<bool> is_max(height.size(), false);
    int cur_max = height[0];
    for(int i=0; i<max_index[0]; ++i){
        if(i==0 || height[i]>=cur_max){
            cur_max = height[i];
            is_max[i] = true;
        }else{
            rainwater+=cur_max-height[i];
        }
    }
    for(auto& i : max_index){
        is_max[i] = true;
    }
    cur_max = height.back();
    for(int i=(int)height.size()-1; i>max_index.back(); --i){
        if(i==(int)height.size()-1 || height[i]>=cur_max){
            cur_max = height[i];
            is_max[i] = true;
        }else{
            rainwater+=cur_max-height[i];
        }
    }

    return rainwater;
}


int main() {
    vector<int> heights{4,2,0,3,2,5};
    cout << trap(heights);

    return 0;
}
