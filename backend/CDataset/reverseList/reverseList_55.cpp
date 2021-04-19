class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
ListNode* reverseList(ListNode* head)
{
	 ListNode* prev{nullptr};
	 for( ; head; head = exchange(head->next, exchange(prev, head)));	 
	 return prev;
}
};