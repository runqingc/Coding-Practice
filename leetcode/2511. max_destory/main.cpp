#include <iostream>
#include <vector>
using namespace std;

int captureForts(vector<int>& forts) {
    int cnt=0, max=0;
    int i=0;
    while (forts[i] == 0)
        ++i;
    if(i>=forts.size()) return 0;
    int start = forts[i];
    for( ; i<forts.size();++i){
        if(forts[i]==0){
            ++cnt;
        }else if(forts[i]==start){
            cnt = 0;
        }else{
            start = -start;
            if(cnt>max) max = cnt;
            cnt = 0;
        }
    }
    return max;

}



int main() {
    vector<int> forts {1,0,0,-1,0,0,0,0,-1,0,0,0,1};
    cout << captureForts(forts)<< endl;
    return 0;
}
