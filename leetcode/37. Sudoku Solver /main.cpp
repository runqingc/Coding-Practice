#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char>>& board){
    for(auto& i: board){
        for(auto& j: i)
            cout << j << ' ';
        cout << endl;
    }
}

// check if num in place [r][c] will conflict with the existing numbers
bool valid(vector<vector<char>>& board, int num, int r, int c){
    char num_char = (char)(num+'0');
    for(int i=0; i<9; ++i){
        if(board[i][c] == num_char || board[r][i] == num_char) return false;
    }
    for(int i=r/3*3; i<r/3*3+3; ++i){
        for(int j=c/3*3; j<c/3*3+3; ++j){
            if(board[i][j]==num_char){
                return false;
            }
        }
    }
    return true;
}

void dfs(vector<vector<char>>& board, int& cnt){
    //check if finished
    if(cnt==0) return;
    //find next empty cell board[r][c]
    int r=-1, c=-1;
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            if(board[i][j]=='.'){
                r = i; c = j; break;
            }
        }
        if(r>=0 && c>=0) break;
    }
    // chose the value for empty cell board[r][c]
    for(int i=1; i<=9; ++i){
        if(valid(board, i, r, c)){
            // put it in board
            board[r][c] = (char)(i+'0');
            --cnt;
            // if cnt>0, dfs
            if(cnt>0){
                dfs(board, cnt);
            }
            // if(cnt==0) return;
            // else undo decision
            if(cnt==0){
                return;}
            else{
                board[r][c]='.';
                ++cnt;
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& board){
    int cnt = 0;
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            if(board[i][j]=='.'){
                ++cnt;
            }
        }
    }
    dfs(board, cnt);
}

int main() {

    vector<vector<char>> board{{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
//    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    print(board);
    return 0;
}
