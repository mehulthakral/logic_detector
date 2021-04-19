class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(ListNode *head) 
{
	ListNode* hare=NULL,*tort=NULL;
	if(head)
	tort=head->next;
	if(tort)
		hare=tort->next;
	while(tort!=NULL&&hare!=NULL&&tort<hare)
	{
		tort=tort->next;
		if(hare->next)
			hare=hare->next->next;
		else hare=NULL;
	}
	return hare!=NULL;
}
};