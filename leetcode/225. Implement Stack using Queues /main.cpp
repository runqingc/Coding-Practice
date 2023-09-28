#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> input;
    queue<int> backup;
public:
    MyStack() = default;

    void push(int x) {
        input.push(x);
    }

    int pop() {
        int size = (int)input.size();
        for(int i=1; i<=size-1; ++i){
            backup.push(input.front());
            input.pop();
        }
        int ans = input.front();
        input.pop();
        queue<int> tmp;
        tmp = input; input = backup; backup = tmp;
        return ans;
    }

    int top() {
        int size = (int)input.size();
        for(int i=1; i<=size-1; ++i){
            backup.push(input.front());
            input.pop();
        }
        int ans = input.front();
        backup.push(input.front());
        input.pop();
        queue<int> tmp;
        tmp = input; input = backup; backup = tmp;
        return ans;
    }

    bool empty() {
        return input.empty();
    }
};


int main() {
    auto s1 = new MyStack;
    s1->push(1);
    cout << s1->top() << endl;
    s1->push(2);
    cout << s1->top() << endl;
    s1->push(3);
    cout << s1->top() << endl;
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;
    cout << s1->pop() << endl;
    return 0;
}
