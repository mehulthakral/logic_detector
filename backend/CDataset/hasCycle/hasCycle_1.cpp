class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            if(slow == fast){
                return true;
            }
            
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};
