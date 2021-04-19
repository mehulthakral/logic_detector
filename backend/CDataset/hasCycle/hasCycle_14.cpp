class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    
    bool hasCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        // slow running in 1 step at a time 
        // fast running in 2 step at a time
    
        while(fast  && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true; // if slow and fast both meets than there must 
                            // a cycle in the linkded list
        }
        return false;
    }
};