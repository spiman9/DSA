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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = count(head);
        if(head == nullptr || !head->next)return head;
        int times = (len - k % len) % len; // update more conditions ** This is important*
        //K can be greater than length thats why we do k%len and also when k is multiple of len we should not rotate
        if(times == 0 || k == 0){
            return head;
        }

        ListNode*last = head;
        
        while(last->next){ // Code to find the last node requireed to connect to head
            last = last->next;
        }

        int i = 0; // 0 1 2
        ListNode* ptr = head;
        while(i != times-1){ // its times -1 because we have to stop one node before the new head
            ptr = ptr->next;
            i++;
        }
        ListNode* newhead = ptr->next; // so new head is next of ptr
        ptr->next = nullptr;
        
        last->next = head;
        head =newhead;
        return head;
    }

    int count(ListNode* head){
        if(!head){
            return 0;
        }
        return 1 + count(head->next);
    }
};