class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        while (head) {
            if (head->val == INT_MIN) return true;
            head->val = INT_MIN;
            head = head->next;
        }
        return false;
    }
};
