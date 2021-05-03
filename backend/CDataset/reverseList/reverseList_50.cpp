class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
		ListNode *cur = head;
		while (cur != NULL){
			ListNode *next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
    }
};