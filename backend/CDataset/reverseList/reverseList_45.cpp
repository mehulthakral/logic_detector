class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head,ListNode* pre = NULL) {
        if(head == nullptr){
            return pre;
        }
        ListNode* next = head->next;
        head->next = pre;
        return reverseList(next,head);
    }
};
