#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
using namespace std;

class treeNode{
public:
    bool isTerminate;
    vector<shared_ptr<treeNode>> children;
    treeNode():isTerminate(false){
        children.resize(26);
    };
    explicit treeNode(bool isTerminate):isTerminate(isTerminate){
        children.resize(26);
    };
};

class WordDictionary {
    bool found;
    shared_ptr<treeNode> root;
public:
    WordDictionary() {
        root = make_shared<treeNode>();
    }
    void addWordToNode(const string& word, int index, shared_ptr<treeNode> root){
        if(root->children[word[index]-'a']==nullptr){
            root->children[word[index]-'a']= make_shared<treeNode>(); 
        }
        if(index<(int)word.size()-1){
            addWordToNode(word, index+1, root->children[word[index]-'a']);
        }
        if(index==(int)word.size()-1){
            root->children[word[index]-'a']->isTerminate = true;
        }
    }

    void addWord(const string& word) {
        addWordToNode(word, 0, root);
    }

    void searchFromNode(const string& word, int index, shared_ptr<treeNode> root){
        if(!found){
            if(word[index]=='.'){  // search all child node
                for(auto child: root->children){
                    if(child != nullptr){
                        if(index==word.length()-1 && child->isTerminate==true){
                            found = true;
                        }else if(index+1<word.length()){
                            searchFromNode(word, index+1, child);
                        }
                    }
                }   
            }else{  // search a single node
                if(root->children[word[index]-'a']!=nullptr){
                    if(index==word.length()-1 && root->children[word[index]-'a']->isTerminate==true){
                        found = true;
                    }else if(index+1<word.length()){
                        searchFromNode(word, index+1, root->children[word[index]-'a']);
                    }
                }
            }
        }
    }
    
    bool search(const string& word) {
        found = false;
        searchFromNode(word, 0, root);
        return found;
    }
};


int main(){

    WordDictionary wordDictionary;
    wordDictionary.addWord("at");
    wordDictionary.addWord("and");
    wordDictionary.addWord("an");
    wordDictionary.addWord("add");

    cout << boolalpha;
    // cout << wordDictionary.search("a") <<endl;
    cout << wordDictionary.search(".at") <<endl;
    wordDictionary.addWord("bat");

    cout << wordDictionary.search(".at") <<endl;
    cout << wordDictionary.search("an.") <<endl;
    cout << wordDictionary.search("a.d.") <<endl;
    cout << wordDictionary.search("b.") <<endl;
    cout << wordDictionary.search("a.d") <<endl;
    cout << wordDictionary.search(".") <<endl;




    return 0;
}