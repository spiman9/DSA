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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = nullptr;
        ListNode* head;
        int carry = 0;
        while(l1 && l2){
            int s = l1->val + l2->val + carry;
            int d = s % 10;
            carry = s / 10;
            ListNode* temp = new ListNode(d);
            if(p == nullptr){
                p = temp;
                head = p;
            }else{
                p->next = temp;
                p = p->next;
            }
            // increment the pointers'
            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry == 0){
            if(l1){
                p->next = l1;
            }else{
                p->next = l2;
            }
        }else{
            if(l1){
                // add to l1
                solve(l1,1 , p);
                p->next = l1;
            }else if(l2){
                solve(l2 , 1 , p);
                p->next = l2;
            }else{
                solve(l2 , 1 , p);
            }
        }

        return head;
    }

    void solve(ListNode* head , int carry , ListNode*p){
        ListNode*prev = nullptr;
        if(head == nullptr){
            ListNode*temp = new ListNode(1);
            p->next = temp;
            cout << "I am here" << endl;
            return;
        }
        while(head && carry == 1){
            int s = head->val + carry;
            int d = s % 10;
            carry = s / 10;
            head->val = d;
            prev = head;
            head = head->next;
        }
        if(head == nullptr && carry == 1){
            ListNode*temp = new ListNode(carry);
            prev->next = temp;
        }
    }
};