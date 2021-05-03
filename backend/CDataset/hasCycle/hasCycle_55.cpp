class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return false;
        
        ListNode * slow=head;
        ListNode * fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};
