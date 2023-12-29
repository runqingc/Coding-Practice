#include <iostream>
#include <vector>
using namespace std;





class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> heap;
        heap.reserve(k);
        auto compare = [](const vector<int>& a, const vector<int>& b){
            return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
        };
        int i;
        for(i=0; i<k; ++i){
            heap.push_back(points[i]);
        }
        make_heap(heap.begin(), heap.end(), compare);
        for( ; i<points.size(); ++i){
            if(compare(points[i], heap.front())){
                pop_heap(heap.begin(), heap.end(), compare);
                heap.pop_back();
                heap.push_back(points[i]);
                push_heap(heap.begin(), heap.end(), compare);
            }
        }
        return heap;
    }
};



int main() {
    Solution s;
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2, 4}};
    auto ans = s.kClosest(points,2);
    for(auto& i :ans ){
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}


//vector<int> distance;
//distance.reserve(k);
//
//
//
//
//
//vector<vector<int>> ans;
//for(auto& point: points){
//int this_dis = point[0]*point[0]+point[1]*point[1];
//if(distance.size()<k){
//distance.push_back(this_dis);
//}
//if(distance.size()==k){
//make_heap(distance.begin(), distance.end());
//}
//if(distance.size()>k){
//if(this_dis<distance.front()){
//pop_heap(distance.begin(), distance.end());
//distance.pop_back();
//distance.push_back(this_dis);
//push_heap(distance.begin(), distance.end());
//}
//}
//}