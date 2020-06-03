// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int add = 0) {
        ListNode* result = NULL;
        ListNode* l3 = NULL;
        while (l1 != NULL && l2 != NULL) {
            int value = (l1 -> val + l2 -> val + add) % 10;
            add = (l1 -> val + l2 -> val + add ) / 10;
            if (l3) {
                l3 -> next = new ListNode(value);
                l3 = l3 -> next;
            } else {
                l3 = new ListNode(value);
                result = l3;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if (add && !l1 && !l2) {
            l3 -> next = new ListNode(add);
        }
        ListNode* temp = new ListNode(0);
        if (l1) {
            l3 -> next = addTwoNumbers(l1, temp, add);
        }
        if (l2) {
            l3 -> next = addTwoNumbers(l2, temp, add);
        }
        
        return result;
    }
};