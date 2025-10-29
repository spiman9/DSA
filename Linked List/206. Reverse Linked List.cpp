/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return solve(head);
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode*r = nullptr , *q = nullptr , * p =head;
        while(p){
            r = q;
            q = p;
            p = p->next;
            // rever the link here'
            q->next = r;
        }
        q->next = r;
        return q;
    }

    ListNode* solve(ListNode*head){
        // if only one element or 2 elements are present
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode*newhead = solve(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};