#include <iostream>
using namespace std;

class MyLinkedList {
private:
    int val;
    MyLinkedList* next;
public:
    // initialize with dummy head
    MyLinkedList():val(-1), next(nullptr){}
    explicit MyLinkedList(int n):val(n), next(nullptr){}

    int get(int index) {
        MyLinkedList* tmp = this;
        for(int cnt=-1; tmp->next; ){
            tmp = tmp->next;
            ++cnt;
            if(cnt==index){
                return tmp->val;
            }
        }
        return -1;
    }

    void addAtHead(int val) {
        auto* tmp = new MyLinkedList(val);
        tmp->next = this->next;
        this->next = tmp;
    }

    void addAtTail(int val) {
        MyLinkedList* tmp = this;
        while(tmp->next!= nullptr){
            tmp = tmp->next;
        }
        auto* node = new MyLinkedList(val);
        tmp->next = node;
    }

    void addAtIndex(int index, int val) {
        int cnt = 0;
        MyLinkedList* tmp = this;
        while(tmp->next!= nullptr){
            if(cnt==index){
                auto node  = new MyLinkedList(val);
                node->next = tmp->next;
                tmp->next = node;
            }
            tmp = tmp->next;
            ++cnt;
        }
        if(cnt==index){
            auto node  = new MyLinkedList(val);
            node->next = tmp->next;
            tmp->next = node;
        }
    }

    void deleteAtIndex(int index) {
        auto tmp = this;
        int cnt = -1;
        for( ;tmp->next; ){
            ++cnt;
            if(cnt==index){
                auto deleteNode = tmp->next;
                tmp->next = tmp->next->next;
                delete deleteNode;
                return ;
            }
            tmp = tmp->next;
        }
    }
};


int main() {
    auto* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->deleteAtIndex(0);

//    myLinkedList->addAtTail(3);
//    myLinkedList->addAtIndex(1, 2);    // linked list becomes 1->2->3
//    cout << myLinkedList->get(1) << endl;              // return 2
//    myLinkedList->deleteAtIndex(1);    // now the linked list is 1->3
//    cout << myLinkedList->get(1) << endl;              // return 3

    return 0;
}
