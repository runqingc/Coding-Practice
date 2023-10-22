#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {

    vector<int> ans(n+1, 0);
    for(int i=1; i<n+1; ++i){
        ans[i] = ans[i-1]+1;
        int num = i-1;
        while((num&1)==1){
            num>>=1;
            --ans[i];
        }
    }
    return ans;
}


int main() {
    auto ret = countBits(5);
    for(auto i: ret){
        cout << i << endl;
    }
    return 0;
}
