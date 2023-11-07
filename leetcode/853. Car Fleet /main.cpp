#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    int fleet = 1;
    vector<int>cars (position.size());
    for(int i=0; i<cars.size(); ++i){
        cars[i] = i;
    }
    sort(cars.begin(), cars.end(), [&position](const int a, const int b)->bool{
        return position[a]>position[b];
    });

    double aheadTime = 1.0*(target-position[cars[0]])/speed[cars[0]];

    for(int i=1; i<cars.size(); ++i){

        // if current car need more time to reach destination
        if(1.0*(target-position[cars[i]])>aheadTime*speed[cars[i]]){
            ++fleet;
            aheadTime = 1.0*(target-position[cars[i]])/speed[cars[i]];

        }

    }

    return fleet;
}



int main() {
    vector<int> position{8,12,16,11,7};
    vector<int> speed{6,9,10,9,7};

    int target = 13;
    std::cout << carFleet(target, position, speed) << std::endl;
    return 0;
}
