class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //create two pointers pre, next
        ListNode* pre=NULL;
        ListNode* next=NULL;
        //Run the loop till we reach the end
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        //return the last pointer
        return pre;
    }
};
