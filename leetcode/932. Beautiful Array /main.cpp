#include <iostream>
#include <vector>
using namespace std;

void beautify(vector<int>& arr, int l, int r){
    // recursion exit:
    if(r-l<=1) return;

    // partition those with odd and even index
    vector<int> tmp(r-l+1);
    int cnt = 0;
    int mid;
    for(int i=l; i<=r; i+=2){
        tmp[cnt++]=arr[i];
    }
    mid=l+cnt-1;
    for(int i=l+1; i<=r; i+=2){
        tmp[cnt++]=arr[i];
    }
    // copy all the tem val to arr
    for(int i=l, j=0; i<=r; ++i, ++j){
        arr[i] = tmp[j];
    }
    beautify(arr, l, mid);
    beautify(arr, mid+1, r);
}


vector<int> beautifulArray(int n) {
    vector<int> arr (n);
    for(int i=0; i<arr.size(); ++i){
        arr[i] = i+1;
    }
    beautify(arr, 0, n-1);
    return arr;
}


int main() {
    auto ans = beautifulArray(7);
    for(auto& i: ans){
        cout << i << " ";
    }

    return 0;
}
