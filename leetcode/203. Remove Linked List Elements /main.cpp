#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val){
            head = head->next;
        }
        if(!head)return head;
        ListNode* tmp = head;
        while(tmp){
            ListNode* i = tmp->next;
            while(i && i->val==val){
                i = i->next;
            }
            tmp->next = i;
            tmp = i;
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
