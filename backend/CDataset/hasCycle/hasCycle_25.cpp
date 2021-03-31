class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        if(head->next == NULL)
            return false;
        if(head->next==head)
            return true;
        ListNode* h=head->next;
        head->next = head;
        return hasCycle(h);
        
    }
};
