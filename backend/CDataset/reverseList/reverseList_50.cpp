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
