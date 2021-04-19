class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
          if(head==NULL || head->next==NULL)
              return head;
         ListNode* p= reverseList(head->next);
         head->next->next=head;
         head->next=NULL;
         return p;   
    }
};