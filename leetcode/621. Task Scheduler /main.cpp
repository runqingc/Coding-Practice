#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int cnt[26] = {0};
        for(auto task:tasks){
            ++cnt[task-'A'];
        }
        int time = 0;
        auto comp = [&cnt](const int& a, const int& b){
            return cnt[a]<cnt[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for(int i=0; i<26; ++i){
            if(cnt[i]>0){
                heap.push(i);
            }
        }
        vector<int> cool(26, 0);
        int num_task = (int) tasks.size();
        while(num_task>0){
            ++time;
            // cool every task
            for(int i=0; i<26; ++i){
                if(cool[i]>0){
                    --cool[i];
                    if(cool[i]==0 && cnt[i]>0){
                        heap.push(i);
                    }
                }
            }

            // do the task with max number
            int this_task = heap.top();
            if(cool[this_task]==0){
                --cnt[this_task];
//                cout << char(this_task+'A') << " ";
                --num_task;
                cool[this_task]+=n+1;
                if(cool[this_task]>0){
                    heap.pop();
                }
            }
        }


        return time;
    }
};



int main() {
    Solution s;
    vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'}; 
    int n = 2;
    cout << s.leastInterval(tasks, n) << endl;
    return 0;
}
