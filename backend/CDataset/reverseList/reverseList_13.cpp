class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        ListNode *current=head;
        ListNode *next=NULL,*prev=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
        return head;
    }
};
