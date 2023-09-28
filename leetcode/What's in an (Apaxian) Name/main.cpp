#include <iostream>
#include <string>
using namespace std;



int main() {

    string community;
    cin >> community;
    int N;
    cin >> N;
    int p=0, b=0, r=0, c=0;
    string tmp;
    for(int i=0; i<N; ++i){
        cin >> tmp;
        if(tmp.find(community)==0){
            ++p;
        }else if(tmp.find(community)==tmp.size()-community.size()){
            ++b;
        }else if(tmp.find(community)==string::npos){
            ++c;
        }else{
            ++r;
        }
    }
    cout << p << " " << "PRINCESS" << endl;
    cout << b << " " << "BARON" << endl;
    cout << r << " " << "PRIEST" << endl;
    cout << c << " " << "COMMONER" << endl;

    return 0;
}
