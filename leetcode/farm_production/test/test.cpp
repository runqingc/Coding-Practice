#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <climits>
#include <random>
#include <cassert>
using namespace std;

long N;
vector<long> d;
vector<long> g;


// calculate the distance between 2 farms
auto calDis = [](vector<long>& d, int x, int y){
    return accumulate(d.begin()+min(x,y), d.begin()+max(x,y), 0);
};


bool ckmin(int &a, const int &b) { return b < a ? a = b, 1 : 0; }


vector<int> hungarian(const vector<vector<int>> &C) {
    const int J = (int)size(C), W = (int)size(C[0]);
    assert(J <= W);
    // job[w] = job assigned to w-th worker, or -1 if no job assigned
    // note: a W-th worker was added for convenience
    vector<int> job(W + 1, -1);
    vector<int> ys(J), yt(W + 1);  // potentials
    // -yt[W] will equal the sum of all deltas
    vector<int> answers;
    const int inf = INT_MAX;
    for (int j_cur = 0; j_cur < J; ++j_cur) {  // assign j_cur-th job
        int w_cur = W;
        job[w_cur] = j_cur;
        // min reduced cost over edges from Z to worker w
        vector<int> min_to(W + 1, inf);
        vector<int> prv(W + 1, -1);  // previous worker on alternating path
        vector<bool> in_Z(W + 1);    // whether worker is in Z
        while (job[w_cur] != -1) {   // runs at most j_cur + 1 times
            in_Z[w_cur] = true;
            const int j = job[w_cur];
            int delta = inf;
            int w_next;
            for (int w = 0; w < W; ++w) {
                if (!in_Z[w]) {
                    if (ckmin(min_to[w], C[j][w] - ys[j] - yt[w]))
                        prv[w] = w_cur;
                    if (ckmin(delta, min_to[w])) w_next = w;
                }
            }
            for (int w = 0; w <= W; ++w) {
                if (in_Z[w]) ys[job[w]] += delta, yt[w] -= delta;
                else min_to[w] -= delta;
            }
            w_cur = w_next;
        }
        // update assignments along alternating path
        for (int w; w_cur != W; w_cur = w) job[w_cur] = job[w = prv[w_cur]];
        answers.push_back(-yt[W]);
    }
    return answers;
}


long findMinCost(int n, vector<long>& d, vector<long>& g){

    // can optimize here: find ways to calculate distance
    // construct the matrix for Hungarian Algorithm
    vector<vector<int>> C(n, vector<int>(2*n, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = g[j] + calDis(d, i, j);
            C[i][j+n] = C[i][j];
        }
    }

    auto ret = hungarian(C);
    
    return ret.back();
}




int main() {
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(1, 20);

    int N;  // Number of farms
    cin >> N;  // Assuming the number of farms is still input by the user

    d.resize(N-1);
    g.resize(N);

    // Generate random distances
    for (int i = 0; i < N - 1; ++i) {
        d[i] = distr(gen);
    }

    // Generate random production costs
    for (int i = 0; i < N; ++i) {
        g[i] = distr(gen);
    }

    cout << "start"<< endl;
    // Find and display the minimum cost
    cout << "Minimum Cost: " << findMinCost(N, d, g) << endl;

    return 0;
}