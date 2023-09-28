#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i=0; int j=0; int cnt = 0;
    for( ;i<g.size() && j<s.size(); ){
        if(s[j]>=g[i]){
            cnt++; i++; j++;
        }else{
            j++;
        }
    }
    return cnt;
}


int main() {
    vector<int> g = {3,1,4,1,5,9};
    vector<int> s = {1,1,4,5,1,4};

    cout << findContentChildren(g, s) << endl;

    return 0;
}
