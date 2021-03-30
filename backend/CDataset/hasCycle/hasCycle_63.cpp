class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            fast = fast->next;
            if(!fast->next)//last node pointing to nulll
                return false;
            fast = fast->next;
            slow = slow->next;
            if(slow == fast)//cycle detected
                return true;
        }
        return false;
    }
};
