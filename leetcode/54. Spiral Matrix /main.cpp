#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int cnt = 0;
    int m = (int) matrix.size();
    int n = (int) matrix[0].size();
    int i=-1, j=-1;
    vector<int> ret(m*n);
    while(cnt<m*n){

        for (++i, ++j; j < n && matrix[i][j] != -120; ++j){
            ret[cnt++] = matrix[i][j];
            matrix[i][j] = -120;
        }
        for( i++, j--; i<m && matrix[i][j] != -120; ++i){
            ret[cnt++] = matrix[i][j];
            matrix[i][j] = -120;
        }
        for(i--, j--; j>=0 && matrix[i][j] != -120; --j){
            ret[cnt++] = matrix[i][j];
            matrix[i][j] = -120;
        }
        for(--i, ++j; i>=0 && matrix[i][j] != -120; --i){
            ret[cnt++] = matrix[i][j];
            matrix[i][j] = -120;
        }

    }

    return ret;
}



int main() {

    return 0;
}
