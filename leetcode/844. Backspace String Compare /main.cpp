#include <iostream>
#include <string>
using namespace std;

int backspace(string& s){
    int fast = 0, slow = 0;
    for( ; fast<s.size(); ++fast){
        if(s[fast]!='#'){
            s[slow++] = s[fast];
        }else{
            if(slow>0) --slow;
        }
    }
    return slow;
}

bool backspaceCompare(string s, string t) {
    int size = backspace(s);
    if(size!= backspace(t)) return false;
    for(int i=0; i<size; ++i){
        if(s[i]!=t[i]) return false;
    }
    return true;
}


int main() {
    std::cout << backspaceCompare("####a#c", "##c") << std::endl;
    return 0;
}
