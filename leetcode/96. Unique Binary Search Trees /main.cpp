#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> res(n+1, 0);
    res[0]=1;
    res[1]=1;
    for(int i=2; i<=n; ++i){
        for(int j=0; j<=i-1; ++j){
            res[i]+=res[j]*res[i-1-j];
        }
    }
    return res[n];
}


int main() {
    cout << numTrees(3) << endl;
    for(int i=1; i<10; ++i){
        cout << numTrees(i) << endl;
    }
    return 0;
}
