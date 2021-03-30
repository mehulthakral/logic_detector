class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode *curr=head;
        ListNode *prev=nullptr;
        ListNode *nxt=nullptr;
         while(curr!=nullptr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
   }
};
