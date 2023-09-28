#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int N, M;

int main(){

    cin >> N >> M;
    getchar();
    vector<string> nameList(N);
    vector<int> STotalList(N);
    vector<int> SAdjustedList(N);
    int final, STotal, MaxSTotal;
    for(int i=0; i<N; ++i){
        cin >> nameList[i];
        vector<int> assignments(M);
        for(int j=0; j<M; ++j){
            cin >> assignments[j];
        }
        cin >> final;
        // sum up STotal
        STotal = accumulate(assignments.begin(), assignments.end(), 0) -
                     *min_element(assignments.begin(), assignments.end()) + final;
        STotalList[i] = STotal;
    }
    MaxSTotal = *max_element(STotalList.begin(), STotalList.end());



    int SGrade;
    for(int i=0; i<N; ++i){
        cout << nameList[i] << " " << STotalList[i] << " ";
        SGrade = ceil(100.0*STotalList[i]/MaxSTotal);
        cout << SGrade << " ";
        if(SGrade>=90 && SGrade<=100){
            cout << "A";
        }else if(SGrade>=80 && SGrade<90){
            cout << "B";
        }else if(SGrade>=70 && SGrade<80){
            cout << "C";
        }else if(SGrade>=60 && SGrade<70){
            cout << "D";
        }else if(SGrade<60){
            cout << "F";
        }
        cout << endl;
    }

    return 0;
}
