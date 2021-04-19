class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
ListNode* reverseList(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* cur = head;
	while (cur) {
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
};