void deleteNode(ListNode* node) 
    {
        //O(1) solution
        
        node->val=node->next->val;
        node->next=node->next->next;
        
        
    }