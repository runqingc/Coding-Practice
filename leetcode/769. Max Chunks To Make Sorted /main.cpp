#include <iostream>
#include <vector>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = (int) (arr.size());
    int cnt = 0;
    int i=0;
    for( ; i<n; ++i){
        int cur_max = arr[i];
        for( ; i<n; ++i){
            if(arr[i]>cur_max){
                cur_max = arr[i];
            }
            if(i==cur_max){
                break;
            }
        }
        ++cnt;
    }
    return cnt;
}


int main() {
    vector<int> arr {1,2,0,3};
    cout << maxChunksToSorted(arr);
    return 0;
}
