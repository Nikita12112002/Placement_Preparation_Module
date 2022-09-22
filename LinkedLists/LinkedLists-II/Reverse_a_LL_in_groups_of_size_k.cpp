class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || k==1)
            return head;
        ListNode * dummy = new ListNode(0);
        dummy->next=head;
        ListNode *curr=head, *nextnode=dummy, *prev=dummy;
        
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        
        while(count>=k)
        {
            curr=prev->next;
            nextnode=curr->next;
            
            for(int i=1 ;i<k ;i++)
            {
                curr->next=nextnode->next;
                nextnode->next=prev->next;
                prev->next=nextnode;
                nextnode=curr->next;
            }
            
            prev=curr;
            count=count-k;
        }
        
        return dummy->next;
    }
};