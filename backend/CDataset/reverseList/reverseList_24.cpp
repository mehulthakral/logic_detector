class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if(!head)
        {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        
        while(curr)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
