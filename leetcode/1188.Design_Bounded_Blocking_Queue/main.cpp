#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <algorithm>
using namespace std;



class BoundedBlockingQueue {
    int* queue;
    int front=0;
    int rear=0;
    int capacity;
    std::mutex mutex;
    std::condition_variable cond1;
    std::condition_variable cond2;
public:
    BoundedBlockingQueue(int capacity):capacity(capacity) {
        queue = new int[capacity];
        std::fill(queue, queue+capacity, -1);
    }
    
    void enqueue(int element) {
        std::unique_lock lock(mutex);
        cond1.wait(lock, [this](){return this->size() < capacity;});
        queue[rear] = element;
        rear = (rear+1)%capacity;
        cond2.notify_all(); // what will happen if I only notify one?
    }
    
    int dequeue() {
        std::unique_lock lock(mutex);
        cond2.wait(lock, [this](){return this->size() > 0;});
        int ans = queue[front];
        queue[front] = -1;
        front = (front+1)%capacity;
        cond1.notify_all();
        return ans;
    }
    
    int size() {
        int size = rear-front;
        return (size>=0)?(size):(size+capacity);
    }

    ~BoundedBlockingQueue(){
        delete[] queue;
    }

};

void produce(BoundedBlockingQueue& queue) {
    while (true) {
        int element = rand() % 100;  // Random element
        queue.enqueue(element);
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work
    }
}

void consume(BoundedBlockingQueue& queue) {
    while (true) {
        int element = queue.dequeue();
        cout << "Dequeued: " << element << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work
    }
}



int main(){

    int capacity = 30;
    BoundedBlockingQueue boundedBlockingQueue(capacity);
    vector<thread> producers(10);
    vector<thread> consumers(10);

    // Create producer threads
    for (int i = 0; i < 10; ++i) {
        producers[i] = thread(produce, ref(boundedBlockingQueue));
    }

    // Create consumer threads
    for (int i = 0; i < 10; ++i) {
        consumers[i] = thread(consume, ref(boundedBlockingQueue));
    }

    // Join threads (in a real application, you might use a different mechanism to stop threads)
    for (int i = 0; i < 10; ++i) {
        producers[i].join();
        consumers[i].join();
    }




    return 0;
}


// this->size() < capacity
// this->size() < capacity;