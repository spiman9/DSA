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
    bool isPalindrome(ListNode* head) {
        /*
        //1. User Stack
        stack<int>st;
        ListNode* p1 = head;
        while(p1){
            st.push(p1->val);
            p1 = p1->next;
        }

        // now check the values
        p1 = head;
        while(!st.empty() && p1->val == st.top()){
            st.pop();
            p1 = p1->next;
        }

        return st.empty() && !p1 ? true : false;

        */


        // Second approch - slow/fast ptr find mid reverse from mid and then compare - reverse affter done
        ListNode* slow = head;
        ListNode*fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //middle = slow
        ListNode*reversehead = reverseList(slow->next);
        fast = reversehead;
        slow = head;
        ListNode*p = head;
        while(p && fast && p != reversehead){
            if(p->val != fast->val){
                return false;
            }
            p = p->next;
            fast = fast->next;
        }

        //now revser it back
        reverseList(slow->next);

        return true;
        
    }


    ListNode* reverseList(ListNode* head) { // revsere a linked list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // store next
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev ahead
            curr = nextNode;                 // move curr ahead
        }

        return prev; // new head
    }
};