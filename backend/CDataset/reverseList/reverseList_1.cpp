class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *node = head; 
        while (node) {
            ListNode* temp = node->next; 
            node->next = prev; 
            prev = node; 
            node = temp; 
        }
        return prev; 
    }
};
