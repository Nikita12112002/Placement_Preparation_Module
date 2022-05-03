//Approach 1- by counting length of LL
 ListNode* middleNode(ListNode* head)
  {
        
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
            
        }
        
        for(int i=0 ;i<count/2 ;i++)
        {
            head=head->next;
        }
        return head;
    }

//Approach 2- slow and fast pointer

 ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }