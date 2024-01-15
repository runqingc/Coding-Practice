#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class Solution {
    vector<int> s;

    int Find(int x){
        if(s[x]<0){
            return x;
        }else{
            return s[x] = Find(s[x]);
        }
    }

    void Union(int x, int y){
        int px = Find(x);
        int py = Find(y);
        if(px!=py){
            if(s[px]<=s[py]){
                s[px] += s[py];
                s[py] = px;
            }else{
                s[py] += s[px];
                s[px] = py;
            }
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        s.resize(V);
        fill(s.begin(), s.end(), -1);
        vector<pair<int, int>> edges;
        edges.reserve(V*(V-1));
        for(int i=0; i<V-1; ++i){
            for(int j=i+1; j<V; ++j){
                edges.push_back({i, j});
            }
        }
        auto cal_dis = [points](const pair<int, int>& a){
            return abs(points[a.first][0]-points[a.second][0])+abs(points[a.first][1]-points[a.second][1]);
        };
        std::sort(edges.begin(), edges.end(), [cal_dis, points](const pair<int, int>& a, const pair<int, int>& b){
            return cal_dis(a)<cal_dis(b);
        });
        int dis = 0;
        int cnt = 0;
        for(auto& edge: edges){
            if(Find(edge.first)!=Find(edge.second)){
                dis += cal_dis(edge);
                Union(edge.first, edge.second);
                ++cnt;
                if(cnt>=V-1) break;
            }
        }
        
        return dis;
    }
};

int main(){

    vector<vector<int>> graph {{0,0},{2,2}, {3,10}, {7,0}, {5,2}};
    Solution s;
    cout << s.minCostConnectPoints(graph);

    return 0;
}