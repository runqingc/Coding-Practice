#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    auto tmp = head;
    // calculate the number of non-empty node
    while(tmp){
        ++size;
        tmp = tmp->next;
    }
    // if head node should be deleted
    if(size==n){
        auto deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }
    int index = 1;
    tmp = head;
    while(tmp){
        if(index==size-n){
            auto deleteNode = tmp->next;
            tmp->next = tmp->next->next;
            delete deleteNode;
            return head;
        }
        ++index;
        tmp = tmp->next;
    }
    return head;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
