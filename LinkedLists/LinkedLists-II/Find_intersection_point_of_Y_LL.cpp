// Approach-1 Brute force - TC:O(n*m) SC:O(n)

 ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        ListNode *temp1=head1;
        ListNode *temp2=head2;
        
        while(temp2!=NULL)
        {
            temp1=head1;
            while(temp1!=NULL)
            {
                if(temp2==temp1)
                  return temp1;
                else
                  temp1=temp1->next;
            }  
            temp2=temp2->next;
        }   
        
        
        return NULL;
    }


//Approach 2 - through hashing Tc:O(m+n) Sc:O(n)

  ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        unordered_map<ListNode* ,int>m;
        ListNode *temp1=head1;
        ListNode *temp2=head2;
        
        while(temp1!=NULL)
        {
            
            m[temp1]++;
            temp1=temp1->next;

        }
        
        while(temp2!=NULL)
        {
            if(m.find(temp2)!=m.end())
                    return temp2;
                else
                    temp2=temp2->next;
        }
        
        return NULL;
    }

//Approach 3- Best TC:O(2m) SC:O(1)

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

    if(head1==NULL || head2==NULL)
            return NULL;
        
        ListNode *temp1=head1;
        ListNode *temp2=head2;
        
        while(temp1!=temp2)
        {
            if(temp1==NULL)
                temp1=head2;
            else
                temp1=temp1->next;
            if(temp2==NULL)
                temp2=head1;
            else
                temp2=temp2->next;
        }
        return temp1;
    }
        