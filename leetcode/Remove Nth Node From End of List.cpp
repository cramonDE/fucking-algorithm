// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.

// 采用双指针的方法
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* back = new ListNode() ;
        back->next = head;
        ListNode* init = head;
        while (head) {
            head = head->next;
            // 取倒数前一位
            if (n <= 0) {
                back = back->next;
            }
            n--;
        }
        // back position to be deleted
         ListNode* next = back ->next;
         back -> next = next -> next;
         if (init != next) return init;
         else return back -> next; 
    }
};