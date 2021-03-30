struct ListNode* reverseList(struct ListNode* head){
	if (! head || ! head->next)
		return head;
 
	struct ListNode *next=head->next;
	head->next=NULL;
	struct ListNode *newNode=reverseList(next);
	next->next=head;
	return newNode;

}