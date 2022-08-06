class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
       //creating a new node approach will take extra space.
        //Below is the approach which is in place;
        
        // method using merge sort
        
        ListNode *head,*temp=NULL;
        
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        if(l1->val>l2->val)
            swap(l1,l2);
        
        head=l1;
        while(l1!=NULL && l2!=NULL)
        {
            temp=NULL;
            while(l1!=NULL && l1->val<=l2->val)
            {
                temp=l1;
                l1=l1->next;
            }
            
            temp->next=l2;
            swap(l1,l2);
        }
        
     
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    if(lists.size()==0)
        return NULL;
    
        while(lists.size()>1)
        {
            lists.push_back(mergeTwoLists( lists[0], lists[1] ));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};