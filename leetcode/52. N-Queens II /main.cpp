#include <iostream>
#include <vector>
using namespace std;

bool checkPlace(vector<int>& chessBoard, int r, int c){
    int tmp_r, tmp_c;
    for(tmp_r=0; tmp_r<chessBoard.size(); ++tmp_r){
        if(chessBoard[tmp_r]!=-1){
            tmp_c = chessBoard[tmp_r];
            if(fabs(1.0*(tmp_r-r)/(tmp_c-c))==1){
                return false; // conflict with some queens
            }
        }
    }
    return true;
}

void dfs(vector<int>& chessBoard, vector<bool>& used, int r, int c, int& cnt){
    //for every pos not used, check if queen in [r+1][i] causes conflict;
    //if so, continue dfs; else, cut
    chessBoard[r] = c;
    used[c]=true;
    //find a column not used
    for(int i=0; i<used.size(); ++i){
        if(!used[i] && checkPlace(chessBoard, r+1, i)){
            //for every placed queen, test if conflict happens when I put queen on [r+1][i]
            // passes test, check if completes
            if(r+1==used.size()-1){
                cnt++;
            }
            else dfs(chessBoard, used, r+1, i, cnt);
        }
    }
    used[c] = false;
    chessBoard[r] = -1;
}


int totalNQueens(int n) {
    if(n==1) return 1;
    vector<int> chessBoard(n, -1);
    vector<bool> used(n, false); // whether there's a queen on column i
    int c = 0;
    int cnt = 0;
    for( ;c<n; ++c){
        dfs(chessBoard,used, 0, c, cnt);
    }
    return cnt;
}


int main() {
    std::cout << totalNQueens(2) << std::endl;
    return 0;
}
