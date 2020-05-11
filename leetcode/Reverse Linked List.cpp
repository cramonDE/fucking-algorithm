/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        if (!head || head -> next == NULL) {
            return prev;
        }
        ListNode* current = head -> next;
        ListNode* next = head -> next;
        prev -> next = NULL;
        while (current != NULL) {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

// 迭代法

public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}


// 递归

public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}

// 递归执行过程当中会出现一半的链表是反向，一半是正向， head.next.next 改变链表的指向，同时head.next = null将原有的关系去掉
