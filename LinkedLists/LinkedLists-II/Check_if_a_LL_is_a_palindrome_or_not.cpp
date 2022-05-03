// Approach 1- Brute force- Tc:O(n) SC:O(n)
// take a array , store all elements of list into array then 
// check the elements of array whether they are palindrome or not

// Approach 2- optimal approach - TC:O(n) SC:O(1)

bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *prev=NULL,*newnode,*temp=slow->next;
        
        while(temp!=NULL)
        {
            newnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=newnode;
        }
        
        slow->next=prev;
        slow=slow->next;
        
        ListNode *dummy=head;
        
        while(slow!=NULL)
        {
            if(slow->val == head->val)
            {
            slow=slow->next;
            head=head->next;
            }
            
            else
                return false;
        }
        
        return true;
    }
    