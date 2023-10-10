#include <iostream>
#include <vector>
using namespace std;

vector<int> getFinalData(vector<int> data, vector<vector<int>> updates) {
    bool totalNegate = false;
    vector<bool> isNegate(data.size(), false);
    for(auto& update: updates){
        isNegate[update[0]-1] = !isNegate[update[0]-1];
        if(update[1]<data.size()) isNegate[update[1]] = !isNegate[update[1]];
    }
    for(int i=0; i<data.size(); ++i){
        if(totalNegate){
            data[i]*=-1;
        }
        if(isNegate[i]){
            data[i]*=-1;
            totalNegate = !totalNegate;
        }
    }
    return data;
}




int main() {
    vector<int> data{3,1,3,0,7};
    vector<vector<int>> updates{{1,4}, {3,5}, {1,4}, {3,5}, {2,3}};
    auto ans = getFinalData(data, updates);
    for(auto& i:ans){
        cout << i << " ";
    }
    return 0;
}
