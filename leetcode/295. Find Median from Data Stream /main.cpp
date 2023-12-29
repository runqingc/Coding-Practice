#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class MedianFinder {
    // stores the number of elements that are larger
    priority_queue<int, vector<int>, greater<>> heap1; // min heap
    // stores the number of elements that are smaller
    priority_queue<int> heap2; // max heap
public:
    MedianFinder() = default;

    void addNum(int num) {
        if(heap1.empty() && heap2.empty()){
            heap1.push(num);
        }else{
            if(num>=heap1.top()){
                heap1.push(num);
            }else{
                heap2.push(num);
            }
            if((int)heap1.size()-(int)heap2.size()>=2){
                int temp = heap1.top();
                heap1.pop();
                heap2.push(temp);
            }
            if(heap2.size()>heap1.size()){
                int temp = heap2.top();
                heap2.pop();
                heap1.push(temp);
            }
        }
    }

    double findMedian() {
        if(heap1.size()==heap2.size()){
            return (heap1.top()+heap2.top())/2.0;
        }else{
            return heap1.top();
        }
    }
};



int main() {
    auto* obj = new MedianFinder();
    obj->addNum(-1);
    cout << obj->findMedian() << endl;
    obj->addNum(-2);
    cout << obj->findMedian() << endl;
    obj->addNum(-3);
    cout << obj->findMedian() << endl;
    return 0;
}
