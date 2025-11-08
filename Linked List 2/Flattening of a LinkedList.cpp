/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        if(!root || !root->next){
            //one node or null
            return root;
        }
        else{
            Node*updatedHead = flatten(root->next);
            return merge(root, updatedHead);
        }
    }
    
    
    Node* merge(Node* p1 , Node* p2){ // merge method
        Node* dummy = new Node(-1);
        Node* res = dummy;
        
        while(p1 && p2){
            if(p1->data < p2->data){
                res->bottom = p1;
                p1 = p1->bottom;
            }else{
                res->bottom = p2;
                p2 = p2->bottom;
            }
            res = res->bottom;
        }
        if(p1)res->bottom = p1;
        else if(p2) res->bottom = p2;
        return dummy->bottom;
    }
};