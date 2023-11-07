#include <iostream>
#include <unordered_set>
#include <queue>
#include <functional>
using namespace std;

struct Compare {
    bool operator()(long long a, long long b) {
        return a > b; // This will create a min-heap instead of the default max-heap.
    }
};

long long nthUglyNumber(long long n) {

    const static vector<long long>primes {2,3,5};
    unordered_set<long long> uset;
    priority_queue<long long, std::vector<long long>, Compare> pq;
    pq.push(1);
    long long cnt = 0;
    while(true){
        long long thisPrime = pq.top();
        pq.pop();
        ++cnt;
        if(cnt==n){
            return thisPrime;
        }
        for(auto prime: primes){
            long long nextPrime = prime*thisPrime;
            if(nextPrime< INT32_MAX && uset.find(prime*thisPrime)==uset.end()){
                pq.push(prime*thisPrime);
                uset.insert(prime*thisPrime);
            }
        }
    }
    return 1;
}


int main() {
    std::cout << nthUglyNumber(1) << std::endl;
    return 0;
}
