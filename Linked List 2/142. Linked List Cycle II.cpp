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
    ListNode *detectCycle(ListNode *head) {
        
        //sfirst approch
        /*
        ListNode *p = head;
        unordered_set<ListNode *>map;
        while(p)
        {
            if(map.find(p) != map.end())
            {
                return p;
            }else{
                map.insert(p);
            }
            p=p->next;
        }
        return nullptr;
        */

        //tortoise and hare solution
        ListNode*slow = head;
        ListNode*fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }

        if(!fast || !fast->next){
            return nullptr; // no looop hrtr
        }

        // now update the slow
        while(slow !=head){
            slow = slow->next;
            head = head->next;
        }
        return slow;
    }
};