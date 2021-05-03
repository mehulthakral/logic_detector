class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
bool hasCycle(ListNode *head) {
	for(ListNode *fast = head, *slow = head; fast && fast->next;)
		if((fast = fast->next->next) == (slow = slow->next))
			return true;
	return false;
}
};