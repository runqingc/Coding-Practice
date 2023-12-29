#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;

struct Field{
    int timestamp;
    string value;
    Field(int t, string v):timestamp(t), value(std::move(v)){};
    bool operator<(const Field& other) const {
        return timestamp<other.timestamp;
    }
};




class TimeMap {
    unordered_map<string, set<Field>> database;

public:
    TimeMap() = default;

    void set(const string& key, const string& value, int timestamp) {
        Field f(timestamp, value);
        database[key].insert(f);
    }

    string get(const string& key, int timestamp) {
        if(database.find(key)==database.end()){
            return "";
        }

        auto it = database[key].lower_bound(Field(timestamp, ""));
        if(it==database[key].begin() && it->timestamp>timestamp){
            return "";
        }
        if(it!=database[key].end() && it->timestamp==timestamp){
            return it->value;
        }
        return (--it)->value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */



int main() {
    auto* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);
    timeMap->get("foo", 1);
    timeMap->get("foo", 3);
    timeMap->set("foo", "bar2", 4);
    timeMap->get("foo", 4);
    timeMap->get("foo", 5);

    return 0;
}
