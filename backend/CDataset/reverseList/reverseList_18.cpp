class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };

ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = NULL;
        
        while(head != NULL){
            ListNode *tempNode  = head->next;
            head->next = prevNode;
            prevNode = head;
            head = tempNode;
        }
    return prevNode;
    }
};