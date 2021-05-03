class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(struct ListNode *head) 
{
    if (!head || !head->next)
        return false;
    
    struct ListNode *slow = head->next, *fast = head->next->next;
    
    while (fast && fast->next)
    {
        if (slow == fast)
            return true;
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}
};