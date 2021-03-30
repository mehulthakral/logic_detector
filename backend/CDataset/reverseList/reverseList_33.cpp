// Recursive In-Place 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head, NULL);
    }
    
    ListNode* helper(ListNode* cur, ListNode* newHead) {
        if (cur == NULL) {
            return newHead;
        }
        ListNode* next = cur->next; // Save next
        cur->next = newHead;
        return helper(next, cur);
    }
};