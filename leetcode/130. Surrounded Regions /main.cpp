#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c, bool& isSurrendered, vector<vector<int>>& island){
    visited[r][c]=true;
    island.emplace_back(vector<int>{r, c});
    if(r==0 || r== board.size()-1 || c==0 || c== board[0].size()-1) isSurrendered = false;
    if(r-1>=0 && board[r-1][c]=='O' && !visited[r-1][c]){
        dfs(board, visited, r-1, c, isSurrendered, island);
    }
    if(r+1<board.size() && board[r+1][c]=='O' && !visited[r+1][c]){
        dfs(board, visited, r+1, c, isSurrendered, island);
    }
    if(c-1>=0 && board[r][c-1]=='O' && !visited[r][c-1]){
        dfs(board, visited, r, c-1, isSurrendered, island);
    }
    if(c+1<board[0].size() && board[r][c+1]=='O' && !visited[r][c+1]){
        dfs(board, visited, r, c+1, isSurrendered, island);
    }
}


void solve(vector<vector<char>>& board) {
    vector<vector<bool>> visited (board.size(), vector<bool>(board[0].size(), false));
    vector<vector<int>> island;
    for(int r=0; r<board.size(); ++r){
        for(int c=0; c<board[0].size(); ++c){
            if(board[r][c]=='O' && !visited[r][c]){
                bool isSurrendered = true;
                island.clear();
                dfs(board, visited, r, c, isSurrendered, island);
                if(isSurrendered){
                    for(auto& i: island){
                        board[i[0]][i[1]]='X';
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<char>> board {{'X','X','X','X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X','O','X','X'}};
    solve(board);
    for(auto& i: board){
        for(auto& j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}


