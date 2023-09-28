#include <iostream>
#include <vector>
using namespace std;


void win(char c){
    if(c=='R'){
        cout << "RED WINS";
    }else if(c=='B'){
        cout << "BLUE WINS";
    }
}

// dfs
// for every spot search N cells right && N cells down && N cells left_down && N cells right down

int X, Y, N;

int main() {
    cin >> X >> Y >> N;
    vector<vector<char>> chessBoard(X, vector<char>(Y));
    for(int i=0;i<X; ++i){
        for(int j=0; j<Y; ++j){
            cin>>chessBoard[i][j];
            getchar();
        }
    }
    int k;
    for(int i=0; i<X; ++i){
        for(int j=0; j<Y; ++j){
            if(chessBoard[i][j]!='O'){
                //search down
                if(i+N<=X){
                    for(k=i; k<i+N; ++k){
                        if(chessBoard[k][j]!=chessBoard[i][j]) break;
                    }
                    if(k==i+N){
                        win(chessBoard[i][j]); return 0;
                    }
                }
                // search right
                if(j+N<=Y){
                    for(k=j; k<j+N; ++k){
                        if(chessBoard[i][k]!=chessBoard[i][j]) break;
                    }
                    if(k==j+N){
                        win(chessBoard[i][j]); return 0;
                    }
                }
                // right down
                if(i+N<=X && j+N<=Y){
                    for(k=0; k<N; ++k){
                        if(chessBoard[i+k][j+k]!=chessBoard[i][j]) break;
                    }
                    if(k==N){
                        win(chessBoard[i][j]); return 0;
                    }
                }
                // left down
                if(i+N<=X && j-N>=-1){
                    for(k=0; k<N; ++k){
                        if(chessBoard[i+k][j-k]!=chessBoard[i][j]) break;
                    }
                    if(k==N){
                        win(chessBoard[i][j]); return 0;
                    }
                }
            }

        }

    }
    cout << "NONE";
    return 0;
}
