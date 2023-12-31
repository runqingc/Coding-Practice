#include <iostream>
#include <string>
using namespace std;

struct treeNode {
     int val;
     treeNode *left;
     treeNode *right;
     treeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void Preorder(treeNode* root, string& s){
    if(root){
        s+= to_string(root->val);
        s+='#';
        if(root->left){
            Preorder(root->left, s);
        }
        if(root->right){
            Preorder(root->right, s);
        }
    }
}

string serialize(treeNode* root) {
    string s;
    Preorder(root, s);
    return s;
}

treeNode* decode(vector<int>::iterator l, vector<int>::iterator r){

    treeNode* root = nullptr;
    if(l>=r) return root;
    // find root
    root = new treeNode(*l);
    auto start = ++l, end = r;
    // find left subtree
    while(l<end && *l<root->val){
        ++l;
    }
    root->left = decode(start, l);
    root->right = decode(l, end);


    return root;
}

treeNode* deserialize(string data) {
    // convert the data to vector<int>
    vector<int> intData;
    string numString;
    for(auto& c: data){
        if(c!='#'){
            numString +=c;
        }else{
            intData.push_back(stoi(numString));
            numString.clear();
        }
    }
    return decode(intData.begin(), intData.end());
}

int main() {
    treeNode* t0 = nullptr;
    treeNode t1(30);
    treeNode t2(20);
    treeNode t3(40);
    treeNode t4(25);
    treeNode t5(35);
    t1.left = &t2;t2.right = &t4;
    t1.right = &t3;
    t3.left = &t5;
    string s = serialize(&t1);
    cout << s;
    treeNode* root = deserialize(s);

    return 0;
}
