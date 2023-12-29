#include <vector>
#include <iostream>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#define MAXN 102

class Solution {
    Node* NodeList[MAXN];
    bool visited[MAXN] = {false};

public:

    Solution(){
        for(int i=1; i<=100; ++i){
            NodeList[i] = new Node(i);
        }
    }

    void dfs(Node* node){
        visited[node->val] = true;
        // visit all the un-visited adjacent node
        for(auto& adjacentNode: node->neighbors){
            NodeList[node->val]->neighbors.push_back(NodeList[adjacentNode->val]);
            if(!visited[adjacentNode->val]){
                dfs(adjacentNode);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }else if(node->neighbors.empty()){
            // single node
            return NodeList[node->val];
        }
        // more than 1 node
        dfs(node);
        return NodeList[node->val];
    }
};



int main(){

    Solution s;

    
    cout << "hello" << endl;

    
    return 0;
}






