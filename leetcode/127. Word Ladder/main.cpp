#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


// bfs
// enqueue root
// find all unvisited adjacent nodes, enqueue

// if s1 and s2 varies exactly 1 character
bool isNeighbor(const string& s1, const string& s2){
    int error = 0;
    for(int i=0; i<s1.size(); ++i){
        if(s1[i]!=s2[i]){
            if(++error>=2) return false;
        }
    }
    if(error==1) return true;
    return false;
}


bool expand(vector<string>& wordList, queue<int>& q, vector<int>& visited, int queueIndex){
    int num = (int) q.size();
    while(num--){
        string s = wordList[q.front()]; q.pop(); // top and pop from q0, get s
        // find all neighbors
        for(int i=0; i<wordList.size(); ++i){
            if(isNeighbor(s, wordList[i])){
                if(visited[i]==-1){
                    visited[i] = queueIndex;
                    q.emplace(i);
                }else if(visited[i]==queueIndex){
                    continue;
                }else if(visited[i]==1-queueIndex){
                    return true;
                }
            }
        }
    }
    return false;
}

// -1: not visited;
// i: visited by qi;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int level = 0; int num;
    queue<int> q0;
    queue<int> q1;
    vector<int> visited(wordList.size()+1, -1);
    //enqueue start word
    q0.emplace((int)wordList.size()); visited[wordList.size()] = 0;
    wordList.push_back(beginWord);
    // enqueue end word
    int i;
    for(i=0; i<wordList.size(); ++i){
        if(wordList[i]==endWord){
            q1.emplace(i); visited[i]=1; break;
        }
    }
    if(i==(int)wordList.size()) return 0; // if end word not found
    while(!q0.empty() && !q1.empty()){
        ++level;
        // enqueue from the one with less element
        if(q0.size()<=q1.size()){
            if(expand(wordList, q0, visited, 0)){
                return level+1;
            }
        }else{
            if(expand(wordList, q1, visited, 1)){
                return level+1;
            }
        }

    }

    return 0;
}



int main() {
    string beginWord = "hit"; string endWord = "cog";
    vector<string> wordList {"hot","dot","dog","lot","log","cog"};

    auto ans = ladderLength(beginWord, endWord, wordList);
    cout << ans << endl;
    return 0;
}

//int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//    int level = 0; int num;
//    queue<int> q0;
//    vector<bool> visited(wordList.size()+1, false);
//    q0.emplace((int)wordList.size()); visited[wordList.size()] = true;
//    wordList.push_back(beginWord);
//    while(!q0.empty()){
//        num = (int)q0.size();
//        ++ level;
//        while(num--){
//            string s = wordList[q0.front()];
//            q0.pop(); // top and pop from q0, get s
//            for(int i=0; i<wordList.size(); ++i){  // find all neighbors of s
//                if(!visited[i] && isNeighbor(s, wordList[i])){
//                    // check of the endWord included in the neighbor
//                    if(wordList[i]==endWord){
//                        return level+1;
//                    }
//                    visited[i] = true;
//                    q0.emplace(i);
//                }
//            }
//        }
//    }
//    return 0;
//}