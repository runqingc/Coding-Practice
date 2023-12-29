#include <iostream>
#include <string>
using namespace std;

struct treeNode{
    treeNode* ptr[26];
    int terminate[26];
    treeNode(): ptr{}, terminate{}{}
};



class Trie {
    treeNode* root;

public:
    Trie() {
        root = new treeNode();
    }
    ~Trie(){
        delete root;
    }

    void insert(const string& word) {
        int cnt = 0;
        treeNode* cur = root;
        for(char c : word){
            ++cnt;
            int index = c-'a';
            if(cnt==word.size()){
                cur->terminate[index] = -1;
            }
            else if(cur->terminate[index]==0){
                cur->terminate[index] = 1;
            }
            if(cur->ptr[index]== nullptr) cur->ptr[index] = new treeNode();
            cur = cur->ptr[index];
        }

    }

    bool search(const string& word) {
        int cnt = 0;
        treeNode* cur = root;
        for(char c : word){
            if(cur== nullptr) return false;
            ++cnt;
            int index = c-'a';
            if(cur->ptr[index]== nullptr){
                return false;
            }
            if(cnt==word.size()){
                if(cur->terminate[index] == -1){
                    return true;
                }else {
                    return false;
                }
            }
            cur = cur->ptr[index];
        }

        return false;
    }

    bool startsWith(const string& prefix) {
        int cnt = 0;
        treeNode* cur = root;
        for(char c : prefix){
            if(cur== nullptr) return false;
            ++cnt;
            int index = c-'a';
            if(cur->ptr[index]== nullptr){
                return false;
            }
            cur = cur->ptr[index];
        }

        return true;

    }


};



int main() {
    Trie* obj = new Trie();

    obj->insert("app");
    obj->insert("apple");
    bool param_2 = obj->search("app");
    bool param_3 = obj->startsWith("app");
    cout << param_2 << endl;
    cout << param_3 << endl;
//    bool param_3 = obj->startsWith(prefix);
    return 0;
}
