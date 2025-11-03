/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // use fast pointer slow pointer approch
        

        // basse case
        if(head == nullptr || head->next == nullptr){
            return false; // one element / 0 element don't form cycle
        }

        ListNode*slow = head;
        ListNode*fast = head->next;

        while(slow && fast && slow != fast){
            //logic
            slow = slow->next; // incremet to one
            fast = fast->next;
            if(fast){
                fast = fast->next; // twice
            }
        }

        return slow != nullptr && fast!= nullptr && slow == fast ? true : false;
    }
};