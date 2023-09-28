#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long

// visit city A
// find next nearest legal() city
const ll infinity = INT64_MAX;
ll N, R, H, M, S;

int main() {

    cin >> N >> R >> H >> M >> S;

    vector<pair<string, ll>> stayTime;
    vector<ll> lastVisit(N, INT64_MIN);
    ll no, stay;
    string name;
    for(int i=0; i<N; ++i){
        cin >> no >> name >> stay;
        stayTime.push_back({name, stay});
    }
    vector<vector<ll>> map(N, vector<ll>(N, -1));
    ll c1, c2, dis;
    for(int i=0; i<R; ++i){
        cin >> c1 >> c2 >> dis;
        map[c1][c2] = dis;
        map[c2][c1] = dis;
    }
    vector<string> footPrint;
    ll T = 0, pos = S;
    while(1){
        // stay and visit current city
        T += stayTime[pos].second;
        footPrint.push_back(stayTime[pos].first);
        // update last visit
        lastVisit[pos] = T;

        ll minDistance = -1;
        ll next;
        for(int i=0; i<N; ++i){
            // check if the city is legal
            if(map[pos][i]!=-1 && T+map[pos][i]>=lastVisit[i]+H && T+map[pos][i]+stayTime[i].second<=M){
                // compare with min distance
                if((minDistance==-1) || ( map[pos][i]<minDistance)){
                    minDistance = map[pos][i]; next = i;
                }
            }

        }
        // if the proper city not found
        if(minDistance==-1){
            break;
        }
        T += map[pos][next];
        // find next city to go pos = ?
        pos = next;

    }
    cout << footPrint[0];
    for(int i=1; i<footPrint.size(); ++i){
        cout << " " << footPrint[i];
    }
    cout << '\n' << T << endl;

    return 0;
}
