bool hasCycle(ListNode *h) 
{             
	for(auto p{h}, q{h}; p and p->next; )
	{
		p=p->next->next;
		q=q->next;
		if(p==q) return true;
	}
	return false;
}
