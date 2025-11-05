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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int grp = count(head) / k;
        ListNode* start = head;
        ListNode* last = nullptr;
        ListNode*lastPrevEnd = nullptr;
        ListNode* nextNode=nullptr,*ans=nullptr;
        while(grp--){
            //do it
            ListNode* cur = start;
            for(int i = 1; i<k;i++){
                cur = cur->next;
            }
            last = cur; // update lastnode
            nextNode = last->next; // update the nextnode
            last->next = nullptr; // delink it


            //reverse
            ListNode* newHead = reverse(start);
            if(!ans)ans = newHead;

            if(lastPrevEnd){
                //then do this
                lastPrevEnd->next = newHead;
            }

            lastPrevEnd = start;
            start = nextNode; // update the start


        }


        if(count(head) % k!=0){
            lastPrevEnd->next = start;
        }

        return ans;
    }

    int count(ListNode* head){
        int ct = 0;
        while(head){
            ct++;
            head=head->next;
        }
        return ct;
    }


    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};