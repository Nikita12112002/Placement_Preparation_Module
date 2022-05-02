ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        if(head->next==NULL)
            return head;
        
        ListNode *prev,*next;
        next=head;
        prev=0;
        
        while(head!=NULL)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next; //note that here head=head->next can not be used bcoz link has been broken we cant access next element
        }
        
        return prev;
    }