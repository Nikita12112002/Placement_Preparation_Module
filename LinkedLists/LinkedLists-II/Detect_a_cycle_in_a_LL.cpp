//Approach 1- brute force TC:O(n) SC:O(n)

//use a hash table , traverse linked list 
// if node is not present in hashtable put it into hashtable 
// else if present in hashtable it means cycle is preseent
// if lists is finished while traversing and we get no node that is already
// present in hashtable it means it doesnot have a cycle .

//Approach 2- Optimal TC:O(n) SC:O(1)
bool hasCycle(ListNode *head) {
        
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
                return true;
        }
        
        return false;
        
    }