class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        
       
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        
        while(fast!=NULL && fast->next!=NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast==slow)
            {
                return true;
            }
        }
        
        return false;
    }
};
