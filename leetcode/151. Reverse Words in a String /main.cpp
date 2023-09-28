#include <iostream>
#include <string>
using namespace std;


// reverse the whole string and eliminate extra space
// reverse each word


string reverseWords(string s) {
    // eliminate extra space

    int cnt = 0, i, j;
    for(i=0;s[i]==' ' ; ++i);

    for( ; i<s.size(); ++i){
        if(i==0 || !(s[i]==' ' && s[i-1]==' ')){
            s[cnt++] = s[i];
        }
    }

    for( ;cnt<i; ++cnt ){
        s.pop_back();
    }
    while(!s.empty() && s.back()==' ')s.pop_back();

    // reverse the whole string
    for(i=0, j=(int)s.size()-1; i<j; ++i, --j)swap(s[i], s[j]);

    int l=0, r=0;
    while(true){
        if(r>=s.size()-1) break;
        for(r=l;r<s.size()-1 && s[r+1]!=' ';++r);
        for(int a=l, b = r; a<b; ++a, --b){ swap(s[a], s[b]);}
        l = r+2;
    }

    return s;
}



int main() {
    string s = " a hello world  a  the sky is blue  ";
    cout << reverseWords(s) << "#";
    return 0;
}
