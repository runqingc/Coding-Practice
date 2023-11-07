#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(long long a, long long b) {
        return a > b; // This will create a min-heap instead of the default max-heap.
    }
};

int nthSuperUglyNumber(int n, vector<int>& primes) {
    unordered_set<long long> uset;
    priority_queue<long long, std::vector<long long>, Compare> pq;
    pq.push(1);
    long long cnt = 0;
    while(true){
        long long thisPrime = pq.top();
        pq.pop();
        ++cnt;
        if(cnt==n){
            return (int)thisPrime;
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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
