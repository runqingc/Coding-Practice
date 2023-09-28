#include<iostream>
#include<string>
using namespace std;

int main(){
    string n1;
    string n2;
    cin >> n1 >> n2;
    if(n1.back()=='e'){
        cout << n1+'x'+n2 << endl;
    }else if(n1.back()=='a' || n1.back()=='i' || n1.back()=='o' || n1.back()=='u'){
        n1[n1.size()-1] = 'e';
        cout << n1+"x"+n2 << endl;
    }else if(n1.size()>=2 && n1.back()=='x' && n1[n1.size()-2]=='e'){
        cout << n1+n2;
    }else{
        cout << n1+"ex"+n2;
    }

    return 0;
}
