class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };


    ListNode* helper(ListNode* prevN,ListNode* nextN){
        ListNode* cur = nextN->next;
        nextN->next = prevN;
        if(cur) return helper (nextN, cur);
        return nextN;
    }
    ListNode* reverseList(ListNode* head) {
        if(head) return helper(NULL, head);
        return head;
    }
};