#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

void printFirst(){
    cout << "first" << endl;
}

void printSecond(){
    cout << "second" << endl;
}

void printThird(){
    cout << "third" << endl;
}



class Foo {
public:
    bool firstFinished;
    bool secondFinished;
    std::mutex mutex;
    std::condition_variable cond1;
    std::condition_variable cond2;

    Foo():firstFinished(false), secondFinished(false) {

    }

    void first(const function<void()>& printFirst) {
        unique_lock<std::mutex> lock(mutex);

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstFinished = true;
        cond1.notify_one();
    }

    void second(const function<void()>& printSecond) {
        unique_lock<std::mutex> lock(mutex);
        cond1.wait(lock, [this]{return firstFinished;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondFinished = true;
        cond2.notify_one();
    }

    void third(const function<void()>& printThird) {
        unique_lock<std::mutex> lock(mutex);
        cond2.wait(lock, [this]{return secondFinished;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};



int main() {
    Foo foo;
    thread t3(&Foo::third, &foo, printThird);
    thread t1(&Foo::first, &foo, printFirst);
    thread t2(&Foo::second, &foo, printSecond);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
