class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if(head==NULL || head->next == NULL)
            return false;
        slow = fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow== fast)
                return true;
        }
        return false;
    }
};