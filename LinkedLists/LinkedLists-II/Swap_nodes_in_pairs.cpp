class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || head->next==NULL)
            return head;
        
        ListNode* dummy = new ListNode();
        ListNode* prev=dummy;
        ListNode* curr = head;
        
        while(curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            prev = curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};