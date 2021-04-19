class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(ListNode *head) {
        while(head != NULL)
        {
            if((head -> next) == (ListNode*)0xa) return true;
            auto k = head -> next;
            head -> next = (ListNode*)0xa;
            head = k;
        }
        return false;

    }
};