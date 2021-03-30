ListNode* reverseList(ListNode* head)
{
	if(!head or !head->next) return head;
	auto root = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return root;
}
