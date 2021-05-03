class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
bool hasCycle(ListNode *head) {
	if (!head)
		return false;
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next) {
		if (slow == fast)
			return true;
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}
};