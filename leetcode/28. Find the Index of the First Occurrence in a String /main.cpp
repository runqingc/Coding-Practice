#include <iostream>
#include <string>
using namespace std;

// KMP
//int strStr(string haystack, string needle) {
//    int n = (int)haystack.size(), m= (int)needle.size();
//    vector<int> next(m, 0);
//    int i, j;
//    for(i=0, j = 1; j<=m-1; ++j){
//        if(needle[i]==needle[j]){
//            next[j] = next[j-1]+1;
//            ++i;
//        }else{
//            for( ; i>=0 && needle[i]!=needle[j]; --i);
//            if(i<0) {next[j] = 0; i=0;}
//            next[j] = i;
//        }
//    }
//    for(i=m-1; i>=1; --i){
//        next[i] = i-1-next[i-1];
//    }
//
//    j = 0;
//    for(i=0; i<haystack.size(); ){
//        // if match
//        if(haystack[i]==needle[j]){
//            if(j==needle.size()-1){
//                return i-m+1;
//            }
//            ++j, ++i;
//        }
//        // if not match
//        else{
//            if(j==0){
//                ++i;
//            }else{
//                j = next[j];
//            }
//        }
//    }
//    return -1;
//}

int strStr(string haystack, string needle) {
    int m= (int)needle.size();
    vector<int> next(m, 0);
    int i, j;
    for(i=0, j = 1; j<=m-2; ++j){
        if(needle[i]==needle[j]){
            next[j+1] = i+1;
            ++i;
        }else{
            for( ; i>0 && needle[i]!=needle[j]; i = next[i]);
            if(needle[i]==needle[j]){
                ++i; next[j+1] = i;
            }else{
                next[j+1] = 0;
            }
        }
    }

    j = 0;
    for(i=0; i<haystack.size(); ){
        // if match
        if(haystack[i]==needle[j]){
            if(j==needle.size()-1){
                return i-m+1;
            }
            ++j, ++i;
        }
            // if not match
        else{
            if(j==0){
                ++i;
            }else{
                j = next[j];
            }
        }
    }
    return -1;
}

int main() {
    string haystack = "adcadcaddcadde";
    string needle = "adcadde";
    cout << strStr(haystack, needle) << endl;
    return 0;
}
