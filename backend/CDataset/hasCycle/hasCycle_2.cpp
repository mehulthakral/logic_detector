class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head; 
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; 
            slow = slow->next; 
            if (fast == slow) return true; 
        }
        return false; 
    }
};
