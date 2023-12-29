#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getMax(vector<int>& a, vector<int>& b, int k){
    int cnt = 0;
    unordered_map<int, int> umap;
    for(auto& num: a){
        if(umap.find(num)==umap.end()){
            umap[num] = 1;
            ++cnt;
        }else{
            ++umap[num];
            if(umap[num]==2)--cnt;
        }
    }



    for(auto& num: b){
        // not in a
        if(umap.find(num)==umap.end() && cnt<a.size() && k>0){

            ++cnt;
            --k;
            if(k==0 || cnt==a.size()){
                break;
            }
        }

    }
    return cnt;
}




int main() {
    vector<int>a {1,1,4,5,5};
    vector<int>b {4,4,3,1,5};
    int k=2;
    cout << getMax(a,b,2);
    return 0;
}
