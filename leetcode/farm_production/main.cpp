#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

long N;
vector<long> d;
vector<long> g;

long totalMinCost = LONG_MAX;


// calculate the distance between 2 farms
auto calDis = [](vector<long>& d, int x, int y){
    return accumulate(d.begin()+min(x,y), d.begin()+max(x,y), 0);
};

// remaining producing power
vector<int> canProduce;
// whether a farm have product
vector<bool> haveProduct;
long numHaveProduct = 0;

void dfs(long currentCost){
    
    for(int i=0; i<N; ++i){
        if(!haveProduct[i]){
            // from those who can supply prodecut, find one
            for(int j=0; j<N; ++j){
                if(canProduce[j]>0){
                    // j can produce, let j produce
                    haveProduct[i] = true;
                    --canProduce[j];
                    currentCost += calDis(d, i, j)+g[j];
                    ++numHaveProduct;
                    // check if the all farm have food
                    // check if pruning is necessary
                    if(numHaveProduct==N || currentCost>=totalMinCost){
                        totalMinCost = min(totalMinCost, currentCost);
                    }else{
                        // next level dfs
                        dfs(currentCost);
                    }
                    // undo decision
                    haveProduct[i] = false;
                    ++canProduce[j];
                    currentCost -= calDis(d, i, j)+g[j];
                    --numHaveProduct;
                }
            }
        }
    }

}



long findMinCost(int n, vector<long>& d, vector<long>& g){

    canProduce.resize(N);
    haveProduct.resize(N);
    fill(canProduce.begin(), canProduce.end(), 2);
    fill(haveProduct.begin(), haveProduct.end(), false);
    
    long currentCost = 0;
    // for those who can self-supply, supply themselves
    for(int i=0; i<g.size(); ++i){
        long minCost = LONG_MAX;
        for(int j=0; j<g.size(); ++j){
            minCost = min(minCost, g[j]+calDis(d, i,j));
        }
        if(g[i]<=minCost){
            haveProduct[i] = true;
            --canProduce[i];
            currentCost += g[i];
            ++numHaveProduct;
        }
    }

    

    // backtracking
    if(numHaveProduct<N){
        dfs(currentCost);
    }else{
        totalMinCost = currentCost;
    }
    
    return totalMinCost;
}


int main(){

    // // input the maximum number of farms
    cin >> N;
    
    d.resize(N-1);
    g.resize(N);
    // input the distance of farms
    for(int i=0; i<N-1; ++i){
        cin >> d[i];
    }
    // input the cost of producing the product
    for(int i=0; i<N; ++i){
        cin >> g[i];
    }

    cout << findMinCost(N, d, g) << endl;

    return 0;
}