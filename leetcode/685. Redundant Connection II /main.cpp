#include <iostream>
#include <vector>
using namespace std;

vector<int> S{0};

int Find(int x){
    if(S[x]<0) return x;
    else return S[x] = Find(S[x]);
}

void Union(int x, int y){
    int root_x = Find(x);
    int root_y = Find(y);
    if(S[root_y]<S[root_x]){
        swap(root_x, root_y);
    }
    S[root_x] += S[root_y];
    S[root_y] = root_x;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

    // check if there is a node with indegree 2
    vector<int> indegree(edges.size()+1, 0);
    int error_node = -1;
    for(auto edge:edges){
        if(edge.back()<indegree.size() && ++indegree[edge.back()]>1) {
            error_node = edge.back();
        }
    }

    if(error_node!=-1){
        // remove one of the edge lead to error node, see if the graph is still connected
        vector<int> earsed;
        vector<int> another;
        int find=0;
        for(auto edge= edges.begin(); edge<edges.end(); ++edge){
            if((*edge).back()==error_node){
                ++find;
                if(find==1){
                    another = *edge;
                }
                if(find==2) {
                    earsed = *edge;
                    edges.erase(edge);
                    break;
                }
            }
        }

        // check connectivity
        for(int i=0; i<=edges.size(); ++i){
            S.emplace_back(-1);
        }
        for(auto edge:edges){
            if(Find(edge[0])== Find(edge[1])){
                return another;
            }else{
                Union(edge[0], edge[1]);
            }
        }
        int neg = 0;
        for(int i=1; i<S.size(); ++i){
            if(S[i]<0){
                ++neg;
                if(neg>=2){
                    return another;
                }
            }
        }
        return earsed;
    }


    // check if there is a loop
    for(int i=0; i<edges.size(); ++i){
        S.emplace_back(-1);
    }
    for(auto edge:edges){
        if(Find(edge[0])== Find(edge[1])){
            return edge;
        }else{
            Union(edge[0], edge[1]);
        }
    }
    return edges.back();
}


int main() {
    vector<vector<int>> edges  {{1,5},{3,2},{2,4},{4,5},{5,3}};
    auto ans = findRedundantDirectedConnection(edges);
    cout << ans[0] << ", " << ans[1];
    return 0;
}
