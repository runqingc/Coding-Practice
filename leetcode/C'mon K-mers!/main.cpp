#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long

int main() {
    ll L, N, k, Q;
    cin>> L >> N >> k >> Q;
    getchar();
    string s;

    for(int i=0; i<L; ++i){
        string tmp;
        cin >> tmp;
        s+=tmp;
    }

    vector<string> input(Q);
    unordered_map<string, int> umap(Q);
    for(int i=0; i<Q; ++i){
        string tmp;
        cin >> tmp;
        umap[tmp] = 0;
        input[i] = tmp;
    }
    string cur ;
    for(int i=0; i+k-1<=N-1; ++i){
        cur = s.substr(i,k);
        if(umap.find(cur)!=umap.end()){
            ++umap[cur];
        }

    }

    for(auto& i:input){
        cout << i << " " << umap[i] << endl;
    }


    return 0;
}
