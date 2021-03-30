bool hasCycle(ListNode *h) 
{             
	for(auto p{h}; p and p->next; )
		if((p=p->next->next)==(h=h->next)) return true;

	return false;
}
