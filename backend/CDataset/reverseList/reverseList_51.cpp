class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        while(currNode) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
};
