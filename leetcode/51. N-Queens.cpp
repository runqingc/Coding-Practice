#include<vector>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;

int N;
    vector<vector<string>> all_slu;

    int is_safe(vector<int> a, int row, int col){
        for(int i=0; i<row; i++){
            if(a[i]==col || col-a[i]==row-i || col-a[i]==i-row){
                return 0;
            }
        }
        return 1;
    }

    void pos(vector<int> a, int row){
        int i, j;
        for(i=0; i<N; i++){
            if(is_safe(a, row, i)){
                vector<int> new_a(a);
                new_a.push_back(i);
                /*if complete*/
                if(row==N-1){
                    vector<string> slu;
                    for(j=0; j<N; j++){
                        string pc(N, '.');
                        pc[new_a[j]] = 'Q';
                        slu.push_back(pc);
                        cout << slu[slu.size()-1]<< endl;
                    }
                    
                    all_slu.push_back(slu);
                }else{
                    if(row+1<N) pos(new_a, row+1);
                }
            }else{
                continue;
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<int> a;
        pos(a, 0);
        return all_slu;
    }

int main(){
    solveNQueens(4);
    return 0;
}