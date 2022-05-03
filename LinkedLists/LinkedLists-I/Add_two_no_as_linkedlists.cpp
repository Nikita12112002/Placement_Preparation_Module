ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1=l1;
        ListNode* temp2=l2;
       ListNode *dummy = new ListNode();
       ListNode* prev=dummy;
        prev->next=NULL;
        int sum=0,carry=0;
        
        while(temp1!=NULL && temp2!=NULL)
        {
            sum = sum + temp1->val+temp2->val+carry;
            
            if(sum<=9)
            {
                ListNode* newnode=new ListNode(sum);
                prev->next = newnode;
                prev=newnode;
                carry=0;
            }
            
            else
            {
                ListNode* newnode=new ListNode(sum%10);
                prev->next=newnode;
                prev=newnode;
                carry=sum/10;
            }
            
            temp1=temp1->next;
            temp2=temp2->next;
            sum=0;
            
        }
        
        while(temp1!=NULL)
        {
                sum=0;
                sum = sum + temp1->val + carry;
                ListNode* newnode=new ListNode(sum%10);
                prev->next = newnode;
                prev=newnode;
                temp1=temp1->next;
                carry = sum/10;
        }
        
        while(temp2!=NULL)
        {
                sum=0;
                sum = sum + temp2->val + carry;
                ListNode* newnode=new ListNode(sum%10);
                prev->next = newnode;
                prev=newnode;
                temp2=temp2->next;
                carry = sum/10;
        }
        if(carry!=0)
        {
            ListNode* newnode=new ListNode(carry);
            prev->next=newnode;
            prev=newnode;
        }
        return dummy->next;
        
    }