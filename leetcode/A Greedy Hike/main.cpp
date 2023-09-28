#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main() {
    int X, Y, x0, y0;
    cin >> X >> Y >> x0 >> y0;
    vector<vector<int>> graph(X, vector<int>(Y));
    for(int i=0; i<X; ++i){
        for(int j=0; j<Y; ++j){
            cin >> graph[i][j];
        }
    }
    vector<int> dir {0,1,-1};
    int i=x0, j=y0;
    int ascend = 0;
    int next_i, next_j;
    for( ; j<Y-1; ){
        // chose path
        int min = INT32_MAX;
        for(auto d: dir){
            if(i+d>=0 && i+d<X){
                if(abs(graph[i][j]-graph[i+d][j+1])<min){
                    min = abs(graph[i][j]-graph[i+d][j+1]);
                    next_i = i+d, next_j = j+1;
                }
            }
        }
        ascend += min;
        i = next_i; j = next_j;
    }

    cout << next_i << " " << next_j << " " << ascend;

    return 0;
}
