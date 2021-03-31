class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0); // to direct the node to reversed list
        ListNode* a = head, *prev = dummy;
        dummy->next = head;
        int len = 0;
        while (a) {
            a = a->next;
            len++;
        }
        
        a = prev->next;
        for (int i=0; i<len-1; i++) {
            ListNode* temp = prev->next;
            prev->next = a->next;
            a->next = a->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};
