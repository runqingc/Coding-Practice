#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue() = default;

    void push(int x) {
        input.push(x);
    }

    int pop() {
        int ans = this->peek();
        output.pop();
        return ans;
    }

    int peek() {
        if(!output.empty()){
            return output.top();
        }
        while (!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};



int main() {
    auto* obj = new MyQueue();
    obj->push(1);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
