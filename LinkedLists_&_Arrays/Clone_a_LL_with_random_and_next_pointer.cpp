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
        
        Node *itr=head;
        Node *front=head;
        // creates a deep copy nodes and updating the pointers
        while(itr!=NULL)
        {
            front =itr->next;
            Node *copy=new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            itr=front;
        }
        
         // set up the random pointer of deep copy nodes
        
        itr=head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL)
            {
                itr->next->random=itr->random->next;
            }
            
            itr=itr->next->next;
        }
        
    // restore the original pointers and also make connection in deep copy list.
        itr=head;
        Node *dummy=new Node(0);
        Node *temp=dummy;
        
        while(itr!=NULL)
        {
            front=itr->next->next;
            temp->next=itr->next;
            itr->next=front;
            temp=temp->next;
            itr=front;
            
        }
        
        return dummy->next;
    }
};