#include <iostream>
#include <queue>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     explicit ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    struct Compare{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare>min_heap;
        for(auto i: lists){
            if(i){
                min_heap.push(i);
            }
        }
        ListNode* ans = nullptr;
        ListNode* end = nullptr;

        while (!min_heap.empty()){
            auto tmp = min_heap.top();
            min_heap.pop();
            if(tmp->next){
                min_heap.push(tmp->next);
            }
            if(!ans){
                ans = tmp;
            }else{
                end->next = tmp;
            }
            end = tmp;
        }
        return ans;

    }
};



int main() {
    auto l3 = ListNode(5);
    auto l2 = ListNode(4, &l3);
    auto l1 = ListNode(1, &l2);
    auto l6 = ListNode(4);
    auto l5 = ListNode(3, &l6);
    auto l4 = ListNode(1, &l5);
    auto l8 = ListNode(6);
    auto l7 = ListNode(2, &l8);

    ListNode* l9 = nullptr;
//    auto l1 = ListNode(1);
//    auto l1 = ListNode(1);
//    auto l1 = ListNode(1);
    vector<ListNode*> lists{&l1, &l4, &l7, l9};
    Solution s1;
    auto ans = s1.mergeKLists(lists);
    auto tmp = ans;
    while(tmp){
        if(tmp!=ans) cout << "->";
        cout << tmp->val;
        tmp = tmp->next;
    }

    return 0;
}
