class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	/*initialize current, next, and previous pointers*/
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
		/*store next*/
            next=curr->next;
			
			/*reverse current node's pointer*/
            curr->next=prev;
			
			/*move pointers one position ahead*/
            prev=curr;
            curr=next;
        }
        head=prev;
		/*return the reversed linked list*/
        return head;
    }
};
