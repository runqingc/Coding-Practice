#include <iostream>
#include <thread>
using namespace std;

void releaseHydrogen(){
    cout << "H";
}

void releaseOxygen(){
    cout << "O";
}


class H2O {

    std::mutex mutex;
    std::condition_variable cond_h;
    std::condition_variable cond_o;
    int numHydrogen = 0;
    int numOxygen = 0;
public:
    H2O() = default;

    void hydrogen(const function<void()>& releaseHydrogen) {
        std::unique_lock lock(mutex);
        cond_h.wait(lock, [this]{return numHydrogen<2;});
        ++numHydrogen;
        if(numHydrogen==2 && numOxygen==1){
            numHydrogen=0; numOxygen=0;
            cond_o.notify_all();
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(const function<void()>& releaseOxygen) {
        std::unique_lock lock(mutex);
        cond_o.wait(lock, [this]{return numOxygen<1;});
        ++numOxygen;
        if(numHydrogen==2 && numOxygen==1){
            numHydrogen=0; numOxygen=0;
            cond_h.notify_all();
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};

int main() {

    int numWater = 3;
    H2O h2O;
    vector<thread> h;
    vector<thread> o;
    h.reserve(numWater*2);
    for(int i=0; i<numWater; ++i){
        h.emplace_back(&H2O::hydrogen, &h2O, releaseHydrogen);
        h.emplace_back(&H2O::hydrogen, &h2O, releaseHydrogen);
        o.emplace_back(&H2O::oxygen, &h2O, releaseOxygen);
    }
    for(auto & i : o){
        i.join();
    }
    for(auto & i :h){
        i.join();
    }
    return 0;
}
