#include <iostream>
#include <thread>
using namespace std;

void printNumber(int number){
    cout << number;
}


class ZeroEvenOdd {
private:
    int n;
    int cnt = 1;
    std::mutex mutex;
    bool printZero = true;
    bool printOdd = true;
    std::condition_variable cond;
public:
    explicit ZeroEvenOdd(int n){
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(const function<void(int)>& printNumber) {

        for(int i=1; i<=n; ++i){
            std::unique_lock<std::mutex> lock(mutex);
            cond.wait(lock, [this]{return printZero;});
            printNumber(0);
            printZero = false;
            cond.notify_all();
        }
    }

    void even(const function<void(int)>& printNumber) {

        for(int i=2; i<=n; i+=2){
            std::unique_lock<std::mutex> lock(mutex);
            cond.wait(lock, [this]{return !printZero && !printOdd;});
            printNumber(cnt);
            ++cnt;
            printOdd = true;
            printZero = true;
            cond.notify_all();
        }
    }

    void odd(const function<void(int)>& printNumber) {

        for(int i=1; i<=n; i+=2){
            std::unique_lock<std::mutex> lock(mutex);
            cond.wait(lock, [this]{return !printZero && printOdd;});
            printNumber(cnt);
            ++cnt;
            printOdd = false;
            printZero = true;
            cond.notify_all();
        }
    }
};




int main() {

    ZeroEvenOdd zeroEvenOdd(5);

    thread A(&ZeroEvenOdd::zero, &zeroEvenOdd, printNumber);
    thread B(&ZeroEvenOdd::even, &zeroEvenOdd, printNumber);
    thread C(&ZeroEvenOdd::odd, &zeroEvenOdd, printNumber);

    A.join();
    B.join();
    C.join();

    return 0;
}
