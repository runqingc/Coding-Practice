#include <iostream>
#include <deque>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {

    int size;
    list<pair<int, int>> lru; // pair<key, value>

    // Hash table: Key is int, value is an iterator to the deque
    using ListIterator = list<pair<int, int>>::iterator;
    unordered_map<int, ListIterator> hash;

public:
    explicit LRUCache(int capacity):size(capacity) {}


    int get(int key) {
        if(hash.find(key)==hash.end()){
            return -1;
        }
        int value = hash[key]->second;
        lru.erase(hash[key]);
        lru.emplace_front(key, value);
        hash[key] = lru.begin();
        return value;
    }

    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            auto it = hash[key];
            hash.erase(key);
            lru.erase(it);
        }
        lru.emplace_front(key, value);

        hash[key] = lru.begin();
        if(lru.size()>size){
            int keyToBeDeleted = lru.back().first;
            hash.erase(keyToBeDeleted);
            lru.pop_back();
        }
    }
};


int main() {
    LRUCache l(10);
    l.put(7,28);
    l.put(7,1);
    l.put(8,15);
    cout << l.get(6) << endl;
    l.put(10,27);
    l.put(8,10);
    cout << l.get(8)<< endl;
    l.put(6,29);
    l.put(1,9);
    cout << l.get(6) << endl;
    l.put(10, 7);
    cout << l.get(1) << endl;
    cout << l.get(2) << endl;
    cout << l.get(13) << endl;
    return 0;
}
