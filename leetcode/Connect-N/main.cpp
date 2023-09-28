#include <iostream>
#include <vector>
using namespace std;

int X, Y, N;
// true = c wins
bool checkRow(vector<vector<char>>& chessBoard, char c){
    for(auto& row: chessBoard){
        int cnt = 0;
        for(auto& i: row){
            if(i==c){
                ++cnt;
                if(cnt==N){
                    return true;
                }
            }else{
                cnt = 0;
            }
        }
    }
    return false;
}

bool checkColumn(vector<vector<char>>& chessBoard, char c){
    for(int i=0; i<chessBoard[0].size(); ++i){
        int cnt = 0;
        for(int j=0; j<chessBoard.size(); ++j){
            if(chessBoard[j][i]==c){
                ++cnt;
                if(cnt>=N){
                    return true;
                }
            }else{
                cnt = 0;
            }
        }
    }
    return false;
}

bool checkDiagonal(vector<vector<char>>& chessBoard, char c){
    int init_i = 0;
    int init_j = (int)chessBoard[0].size()-1;
    int i, j;
    for(int d=0; d<chessBoard.size()+chessBoard[0].size()-1; ++d){
        int cnt = 0;
        for(i = init_i, j = init_j; i<chessBoard.size()&& j<chessBoard[0].size(); ++i, ++j){
//            cout << chessBoard[i][j];
            if(chessBoard[i][j]==c){
                ++cnt;
                if(cnt>=N){
                    return true;
                }
            }else{
                cnt = 0;
            }

        }
//        cout << '#';
        // reset init_i and init_j
        if(init_j>=1){
            --init_j;
        }else {
            ++init_i;
        }
    }
    return false;
}

bool checkDiagonal2(vector<vector<char>>& chessBoard, char c){
    int init_i = 0;
    int init_j = 0;
    int i, j;
    //for every diagonal
    for(int d=0; d<chessBoard.size()+chessBoard[0].size()-1; ++d){
        int cnt = 0;
        for(i=init_i, j=init_j; i<chessBoard.size()&& j<chessBoard[0].size(); ++i, --j){
//            cout << chessBoard[i][j];
            if(chessBoard[i][j]==c){
                ++cnt;
                if(cnt>=N){
                    return true;
                }
            }else{
                cnt = 0;
            }
        }
//        cout << '#';
        if(init_j!=chessBoard[0].size()-1){
            ++init_j;
        }else{
            ++init_i;
        }

    }

    return false;
}


int main() {
    // read in graph

    cin >> X >> Y >> N;
    vector<vector<char>> chessBoard(X, vector<char>(Y));
    for(int i=0;i<X; ++i){
        for(int j=0; j<Y; ++j){
            cin>>chessBoard[i][j];
            getchar();
        }
    }

//    checkDiagonal(chessBoard, 'B');
//    checkDiagonal2(chessBoard, 'B');
    // check if B wins
    if(checkRow(chessBoard, 'B') || checkColumn(chessBoard, 'B') || checkDiagonal(chessBoard, 'B') || checkDiagonal2(chessBoard, 'B')){
        cout << "BLUE WINS"; return 0;
    }
    // check if R wins
    else if(checkRow(chessBoard, 'R') || checkColumn(chessBoard, 'R') || checkDiagonal(chessBoard, 'R') || checkDiagonal2(chessBoard, 'R')){
        cout << "RED WINS"; return 0;
    }else{
        cout << "NONE";
    }

    return 0;
}
