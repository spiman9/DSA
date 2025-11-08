/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*>mp1; // stores the correspondence of the deep copy
        unordered_map<Node* , Node*>mp2; // stores the correspondence of the random of first LL

        Node* p = head;
        Node* newHead = new Node(-1);
        Node* q = newHead;
        while(p){
            //for creating copy nodes
            Node*temp = new Node(p->val);
            q->next = temp;
            q=q->next;

            //increment the p
            mp1[p] = q;
            mp2[p] = p->random; // random of first list
            p= p->next;
        }


        p = head;
        q = newHead->next;
        while(q){
            q->random = mp1[mp2[p]]; // first find the value of random in first then find the correspondence in the second list
            q = q->next;
            p=p->next;
        }
        return newHead->next;

        
    }
};