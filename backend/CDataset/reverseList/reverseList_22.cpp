class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
  ListNode* helper(ListNode* head, ListNode* prev) {
        if (!head) return prev;
        ListNode* next = head->next;
        head->next = prev;
        return helper(next, head);
      
        
    }
    
    ListNode* reverseList(ListNode* head) {       
        return helper (head, NULL);
        
    }
};