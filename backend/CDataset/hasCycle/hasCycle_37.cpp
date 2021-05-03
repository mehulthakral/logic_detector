class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) 
    {
        ListNode* slow, *fast;
        
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
        
        slow = head;
        fast = slow->next;
        while( fast !=  NULL )
        {
            if( fast == slow)
            {
                return true;
            }
            slow = slow->next;
            if( fast->next && fast->next->next)
                fast = fast->next->next;
            else
                fast = fast->next;
        }
        return false;
    }
};
