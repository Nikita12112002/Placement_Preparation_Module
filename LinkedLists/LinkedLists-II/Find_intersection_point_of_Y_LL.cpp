// Approach-1 Brute force - TC:O(n*m) SC:O(n)
// take each node of list 2 and for it traverse full list1,
// if a node of list1 and list2 matches then return that node 
// otherwise there is no intersection point
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
// same approach as previous only hashmap is used to store address

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
        