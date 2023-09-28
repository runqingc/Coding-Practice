#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void Preorder(TreeNode* root, string& s){
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

string serialize(TreeNode* root) {
    string s;
    Preorder(root, s);
    return s;
}

TreeNode* decode(vector<int>::iterator l, vector<int>::iterator r){

    TreeNode* root = nullptr;
    if(l>=r) return root;
    // find root
    root = new TreeNode(*l);
    auto start = ++l, end = r;
    // find left subtree
    while(l<end && *l<root->val){
        ++l;
    }
    root->left = decode(start, l);
    root->right = decode(l, end);


    return root;
}

TreeNode* deserialize(string data) {
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
    TreeNode* t0 = nullptr;
    TreeNode t1(30);
    TreeNode t2(20);
    TreeNode t3(40);
    TreeNode t4(25);
    TreeNode t5(35);
    t1.left = &t2;t2.right = &t4;
    t1.right = &t3;
    t3.left = &t5;
    string s = serialize(&t1);
    cout << s;
    TreeNode* root = deserialize(s);

    return 0;
}
