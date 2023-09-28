#include <iostream>
#include <string>
using namespace std;


int main() {

    string f, l;
    cin >> f >> l;
    int n = (int)l.size();
    if(n==5) --n;
    cout << f << " ";
    while(n--){
        cout << l;
    }

    return 0;
}
