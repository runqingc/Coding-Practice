#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        deque<int> q;
        vector<int> indegree(numCourses, 0);
        vector<unordered_set<int>> relations(numCourses);
        for(auto& prerequisite: prerequisites){
            indegree[prerequisite[0]]++;
            relations[prerequisite[1]].insert(prerequisite[0]);
        }
        for(int i=0; i<numCourses; ++i){
            if(indegree[i]==0){
                q.push_back(i);
            }
        }
        int complete = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop_front();
            ++complete;
            for(auto c:relations[course]){
                indegree[c]--;
                if(indegree[c]==0){
                    q.push_back(c);
                }
            }
        }
        return complete == numCourses;
    }
};



int main(){

    return 0;
}