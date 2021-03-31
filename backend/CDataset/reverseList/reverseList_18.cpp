*ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = NULL;
        
        while(head != NULL){
            ListNode *tempNode  = head->next;
            head->next = prevNode;
            prevNode = head;
            head = tempNode;
        }
    return prevNode;
    }
