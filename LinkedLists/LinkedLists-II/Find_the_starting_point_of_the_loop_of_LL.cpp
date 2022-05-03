// also known as linked lists cycle II at leetcode

//Approach-1 : Brute force -using hashmap TC:O(n) , SC:O(n);
// hash every node and if node already exists in hashtable it means 
//that is the starting point

//Approach-2 : using slow and fast pointer TC:O(n) SC:O(1)

ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)
          return NULL;
        ListNode *slow=head ,*fast=head,*temp=head;
        int flag=0;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                flag=1;
                break;
            }
                
        }
        
       if(flag==1)
       {
           while(slow!=temp)
           {
               temp=temp->next;
               slow=slow->next;
               
           }
           return temp;
       }
           
       return NULL; 
    }

