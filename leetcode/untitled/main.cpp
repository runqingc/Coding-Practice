#include <iostream>
#include<string>
using namespace std;




int main() {
//    int n1 = 10;
//    int n2 = 10000;
//    int* p1 = &n1;
//    int* p2 = &n2;
//
//    //serialize
//    char *pc = new char[sizeof(int)];
//    int offset = 0;
//    memcpy(pc, p1, sizeof(int));
//    string s;
//    s += *pc;
//    offset+=sizeof(int);
//    memcpy(pc, p2, sizeof(int));
//    s += *pc;
//    cout << s.size() << endl;
//    cout << s << endl;
//
//    // deserialize
//    char* pc2 = const_cast<char *>(s.c_str());
//    int offset2 = 0;
//    int* n3 = new int;
//    memcpy(n3, pc2, sizeof(int));
//    offset2 += sizeof(int);
//    int* n4 = new int;
//    memcpy(n4, pc2+offset, sizeof(int));
//    cout << *n3 << endl;
//    cout << *n4 << endl;
    cout << to_string(-1) << "#" << endl;
    return 0;
}
