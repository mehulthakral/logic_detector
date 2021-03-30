class Solution {
public:
    bool hasCycle(ListNode *head) {
        int test=-1*999999;
        while(head)
        {
            if(head->val==test)
                return true;
            head->val=test;
            head=head->next;
        }
        return false;
    }
};
