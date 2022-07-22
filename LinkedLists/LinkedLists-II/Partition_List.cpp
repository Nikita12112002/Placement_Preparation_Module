class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* left=new ListNode(0);
        ListNode*  right=new ListNode(0);
        ListNode *leftend,*rightend;
        leftend=left;
        rightend=right;
        
        while(head!=NULL)
        {
            if(head->val<x)
            {
                leftend->next=head;
                leftend=leftend->next;
            }
            else
            {
                rightend->next=head;
                rightend=rightend->next;
            }
            
            head=head->next;
        }
        
        leftend->next=right->next;
        rightend->next=NULL;
        
        return left->next;
    }
};