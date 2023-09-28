#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> route;
    vector<string> cur;

    int E;

    void dfs(vector<vector<int>>& graph, vector<string>& record, int startCityIndex, int routeIndex){
        if(!route.empty()) return;
        // pick any possible destination
        for(int endCityIndex = 0; endCityIndex<record.size(); ++endCityIndex){
            if(!route.empty()) return;
            // if there is a possible route
            if(graph[startCityIndex][endCityIndex]>0){

                // chose the road
                graph[startCityIndex][endCityIndex]--;
                ++routeIndex;
                cur.push_back(record[endCityIndex]);

                if(routeIndex==E){
                    route.assign(cur.begin(), cur.end());
                    return;
                }

                dfs(graph, record, endCityIndex, routeIndex);

                // undo the decision
                cur.pop_back();
                --routeIndex;
                graph[startCityIndex][endCityIndex]++;

            }


        }

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        E = (int)tickets.size();
        unordered_map<string, int> airport;
        vector<string> record;
        int id = 0;
        // find all airports
        for(auto& ticket: tickets){
            for(auto& city: ticket){
                if(airport.find(city)==airport.end()){
                    record.push_back(city);
                    airport[city] = id++;
                }
            }
        }
        sort(record.begin(), record.end());
        airport.clear();
        id = 0;
        for(auto& city:record ){
            airport[city] = id++;
        }

        // build graph
        vector<vector<int>> graph(record.size(), vector<int>(record.size(), 0));
        for(auto& ticket: tickets){
            ++graph[airport[ticket[0]]][airport[ticket[1]]];
        }
        // search
        dfs(graph, record, airport["JFK"], 0);
        route.insert(route.begin(), "JFK");
        return route;
    }
};


int main() {
    Solution s1;
    vector<vector<string>> tickets {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},
                                    {"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    vector<string> ret = s1.findItinerary(tickets);
    for(auto& i: ret){
        cout << i << " ";
    }
    return 0;
}
