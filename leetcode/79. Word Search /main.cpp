#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c, bool& flag, string& word, int start){
    visited[r][c]=true;
    if(start==word.length()-1){
        flag = true; return;
    }
    if(r-1>=0 && !visited[r-1][c] && board[r-1][c] == word[start+1]){
        dfs(board, visited, r-1, c, flag, word, start+1);
    }
    if(r+1<board.size() && !visited[r+1][c] && board[r+1][c] == word[start+1]){
        dfs(board, visited, r+1, c, flag, word, start+1);
    }
    if(c-1>=0 && !visited[r][c-1] && board[r][c-1] == word[start+1]){
        dfs(board, visited, r, c-1, flag, word, start+1);
    }
    if(c+1<board[0].size() && !visited[r][c+1] && board[r][c+1] == word[start+1]){
        dfs(board, visited, r, c+1, flag, word, start+1);
    }
    visited[r][c] = false;
}

bool exist(vector<vector<char>>& board, string word) {
    bool flag = false;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for(int r=0; r<board.size(); ++r){
        for(int c = 0; c<board[0].size(); ++c){
            if(board[r][c]==word[0]){
                dfs(board, visited, r, c, flag, word, 0);
            }
            if(flag) return true;
        }
    }
    return flag;
}

int main() {
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string word = "ABCESEEEFS";
    std::cout << exist(board, word) << std::endl;
    return 0;
}
