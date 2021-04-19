class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *start = head;
        ListNode *end = start->next;
        start ->next = NULL;
        start = end;
        end = end ->next;
		
        while (end != NULL){
            start->next = head;
            head = start;
            start = end;
            end = end->next;
        }
        start->next = head;
        head = start;
        return head;
    }
};
