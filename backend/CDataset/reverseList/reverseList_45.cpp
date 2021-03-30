class Solution {
public:
    ListNode* reverseList(ListNode* head,ListNode* pre = NULL) {
        if(head == nullptr){
            return pre;
        }
        ListNode* next = head->next;
        head->next = pre;
        return reverseList(next,head);
    }
};
