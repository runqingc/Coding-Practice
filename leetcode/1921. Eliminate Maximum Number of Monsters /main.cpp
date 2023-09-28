#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// always kills the monsters who will reach city first
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<double> time(dist.size());
    for(int i=0; i<dist.size(); ++i){
        time[i] = 1.0*dist[i]/speed[i];
    }
    std::sort(time.begin(), time.end());
    for(int i=0; i< time.size(); ++i){
        if(i>=time[i]){
            return i;
        }
    }
    return (int)dist.size();
}


int main() {
    vector<int> dist {1,3,4};
    vector<int> speed{1,1,1};
    cout << eliminateMaximum(dist, speed);
    return 0;
}



