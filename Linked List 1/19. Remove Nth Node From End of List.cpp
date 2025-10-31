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
    int solve(ListNode*head){
        if(head == nullptr){
            return 0;
        }
        return 1 + solve(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = solve(head);
        int eleToRemove = len - n;
        int start = 0;
        ListNode* cur= head;
        ListNode*prev = NULL;
        if(eleToRemove == 0){
            return head ? head->next : NULL;
        }
        while(start != eleToRemove){
            prev = cur;
            cur = cur->next;
            start = start+1;
        }
        prev ->next = cur->next;
        cur = nullptr;
        return head;
    }
};