#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    if(ratings.size()==1) return 1;
    int cnt = 0;
    int* cookies = new int[sizeof(int)*ratings.size()];
    memset(cookies, 0, sizeof(int)*ratings.size());
    for(int i=0; i<ratings.size(); i++){
        // find start point of topological sort
        if((i==0 && ratings[i+1]>=ratings[i]) ||
          (i==ratings.size()-1 && ratings[i-1]>=ratings[i]) ||
          (i>0 && i<ratings.size()-1 && ratings[i-1]>=ratings[i] && ratings[i+1]>=ratings[i])
        ){
            cookies[i] = 1;
            //backward, find the node with indegree = 0
            for(int j=i-1; j>=0 && cookies[j]==0 ; j--){
                if(j-1>=0 && ratings[j-1]>=ratings[j] && ratings[j]>ratings[j+1]){
                    cookies[j] = cookies[j+1]+1;
                }else if(j-1>=0 && cookies[j-1]!=0 && ratings[j]>ratings[j+1]){
                    cookies[j] = max(cookies[j+1], cookies[j-1])+1; break;
                }else if(j==0 && ratings[j]>ratings[j+1]){
                    cookies[j] = cookies[j+1]+1;
                }
            }

            //forward, find the node with indegree = 0
            for(int j=i+1; (j==ratings.size()-1 && ratings[j]>ratings[j-1]) ||
                    (j<ratings.size()-1 && ratings[j]>ratings[j-1] && ratings[j+1]>=ratings[j]); j++) {
                cookies[j] = cookies[j-1] + 1;
            }
        }
    }

    for(int i=0; i<ratings.size(); i++){
        cnt += cookies[i];
    }
    delete[] cookies;
    return cnt;
}

int main() {
    vector<int> r {29,51,87,87,72,12};
    cout << candy(r) << endl;
    return 0;
}
