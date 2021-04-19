class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* n1 = head;
        ListNode* n2 = head->next ? head->next->next : nullptr;
        if (!n2) return false;
        
        while (n1 != n2) {
            n1 = n1->next;
            n2 = n2->next ? n2->next->next : nullptr;
            if (!n2) return false;
        }
        return true;
    }
};
