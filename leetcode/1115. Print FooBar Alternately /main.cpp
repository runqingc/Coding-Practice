#include <iostream>
#include <thread>
#include <condition_variable>
using namespace std;

void printFoo(){
    cout << "foo";
}

void printBar(){
    cout << "bar";
}


class FooBar {
private:
    int n;
    std::mutex mutex;
    std::condition_variable cond1;
    bool flag;
public:
    explicit FooBar(int n):flag(true) {
        this->n = n;
    }

    void foo(const function<void()>& printFoo) {

        for (int i = 0; i < n; i++) {

            unique_lock<std::mutex> lock(mutex);
            cond1.wait(lock, [this]{return flag;});
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = false;
            cond1.notify_one();
        }
    }

    void bar(const function<void()>& printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<std::mutex> lock(mutex);
            cond1.wait(lock, [this]{return !flag;});
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = true;
            cond1.notify_one();
        }
    }
};



int main() {
    FooBar fooBar(3);
    thread A(&FooBar::foo, &fooBar, printFoo);
    thread B(&FooBar::bar, &fooBar, printBar);

    A.join();
    B.join();

    return 0;
}
