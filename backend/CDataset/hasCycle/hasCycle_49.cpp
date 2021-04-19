class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        if (head==NULL) 
			return false;
        
		ListNode *slow=head;
        ListNode *fast=head;
        
        while (fast->next!=NULL && fast->next->next!=NULL)
		{
            slow=slow->next;
            fast=fast->next->next;
            
			if (slow==fast) 
				return true;
        }
        return false;
    }
};