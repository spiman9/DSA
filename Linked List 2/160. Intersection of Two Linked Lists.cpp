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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // vector<ListNode*> vec;'


        // 2 pointers
        // Remember 5+6 = 11
        // Remember 6+5 = 11
        ListNode*p1 = headA;
        ListNode*p2 = headB;

        while(p1 != p2){
            if(!p1){
                p1 = headB;
            }
            p1 = p1->next;
            if(!p2){
                p2 = headA;
            }
            p2 =p2->next; 
        }

        return p2;


        //first Approch
        /*
        map<ListNode* , bool> mp;
        ListNode*p = headA;
        while(p){
            // vec.push_back(p);
            mp[p] = true;
            p=p->next;
        }

        p = headB;
        while(p){
            if(mp.find(p) != mp.end()){
                return p;
            }
            p = p->next;
        }

        return nullptr;

        */
    }
};