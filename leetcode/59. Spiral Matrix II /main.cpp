#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>matrix(n, vector<int>(n, -1));
    int num=1, i=-1, j=-1;
    while(num<=n*n){
        for( i++, j++; j<n && matrix[i][j]==-1; ++j){
            matrix[i][j] = num++;
        }
        for(i++, j--; i<n && matrix[i][j]==-1; ++i){
            matrix[i][j] = num++;
        }
        for(i--, j--; j>=0 && matrix[i][j]==-1; --j){
            matrix[i][j] = num++;
        }
        for(i--, j++; i>=0 && matrix[i][j]==-1; --i){
            matrix[i][j] = num++;
        }
    }


    return matrix;
}



int main() {
    vector<vector<int>>matrix = generateMatrix(5);
    for(auto& i: matrix){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
