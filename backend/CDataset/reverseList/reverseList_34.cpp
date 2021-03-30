class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        
        while (current) {
            
            // Reverse node 
            next = current->next;
            current->next = prev;
            
            // For next iteration
            prev = current;
            current = next;
        }
        
        // Outside of while loop current is NULL that's why we are out of while but prev has the last node 
        // which is now the first node
        return prev;
        
    }
};
