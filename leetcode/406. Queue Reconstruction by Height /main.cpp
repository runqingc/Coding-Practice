#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // sort according to height
    sort(people.begin(), people.end(), [&](const vector<int>& a, const vector<int>& b)->bool{
        return a[0]<b[0];
    });
    vector<vector<int>> people_copy(people);
    vector<vector<int>> ret;
    for(int i=0; i<people.size(); i++){
        //find one with min height among those satisfied
       int min_index = -1;
        for(int j=0; j<people.size(); j++){
            // valid: 1.not chosen; 2.right people num before
            if(people[j][1]==0){
                 min_index = j; break;
            }
        }
        ret.push_back(people_copy[min_index]);
        people[min_index][1] = -1;
        // update
        for(int j=0; j<people.size(); j++){
            if(people[min_index][0]>=people[j][0]){
                people[j][1]--;
            }
        }
    }
    return ret;
}

int main() {
    vector<vector<int>> people{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<vector<int>> ret = reconstructQueue(people);
    for(auto& i: ret){
        cout << i[0] <<"," << i[1] << " ";
    }
    return 0;
}
