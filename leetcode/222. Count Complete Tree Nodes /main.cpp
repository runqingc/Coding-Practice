#include <iostream>
#include <cmath>
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};

int cnt = 0;

int leftPath(treeNode* root) {
    if (!root) return 0;
    int sum = 0;
    while (root) {
        ++sum;
        root = root->left;
    }
    return sum;
}
int rightPath(treeNode* root){
    if(!root) return 0;
    int sum = 0;
    while(root){
        ++sum;
        root = root->right;
    }
    return sum;
}



void count(treeNode* root) {
    if (!root) return;
    int l = leftPath(root);
    int r = rightPath(root);
    if ( l==r ) {
        cnt+=(int)pow(2,l)-1;
        return;
    }
    cnt++;
    if(root->left) count(root->left);
    if(root->right) count(root->right);
}

int countNodes(treeNode* root) {
    count(root);
    return cnt;
}

int main() {
    auto t1 = new treeNode(1);
    auto t2 = new treeNode(2);
    auto t3 = new treeNode(3);
    auto t4 = new treeNode(4);
    auto t5 = new treeNode(5);
    auto t6 = new treeNode(6);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    countNodes(t1);
    cout << cnt;
    return 0;
}
