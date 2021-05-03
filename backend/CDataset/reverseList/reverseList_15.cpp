class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        ListNode *current, *previous, *next;
        current = head;
        previous = NULL;
        
        while(current){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        head = previous;
        return head;
    }
};
