#include <iostream>
#include <deque>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    deque<int> q;
    vector<int> ans(temperatures.size(), 0);
    for(int i=0; i<temperatures.size(); ++i){
        if(q.empty()){
            q.push_back(i);
        }else{
            while(!q.empty() && temperatures[q.back()]<temperatures[i]){
                ans[q.back()] = i-q.back();
                q.pop_back();
            }
            q.push_back(i);
        }
    }
    return ans;

}





int main() {
    vector<int> t{73,74,75,71,69,72,76,73};
    auto ret = dailyTemperatures(t);
    for(auto& i: ret){
        cout << i << " ";
    }
    return 0;
}
