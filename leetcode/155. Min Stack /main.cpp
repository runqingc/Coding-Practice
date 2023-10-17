#include <iostream>
#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> values;
    vector<int> mins;


public:
    MinStack(){};

    void push(int val) {
        values.push_back(val);
        if(mins.empty() || val<=mins.back()){
            mins.push_back(val);
        }
    }

    void pop() {
        if(!values.empty()){
            int tmp = values.back();
            values.pop_back();
            if(!mins.empty() && mins.back()==tmp){
                mins.pop_back();
            }
        }
    }

    int top() {
        if(!values.empty()){
            return values.back();
        }
        return -1;
    }

    [[nodiscard]] int getMin() const {
        return mins.back();
    }
};

int main() {
    auto* minStack= new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin(); // return -3
    minStack->pop();
    minStack->top();    // return 0
    minStack->getMin(); // return -2
    return 0;
}
