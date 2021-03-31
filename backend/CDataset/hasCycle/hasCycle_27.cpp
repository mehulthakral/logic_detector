    bool hasCycle(ListNode *head) {
        if(head == NULL) {
            return false;
        }
        ListNode* iter = head;
        ListNode* last = NULL;
        while(iter->next != NULL) {
            last = iter;
            iter = iter->next;
            if(iter == head) {
                return true;
            }
            last->next = head;
        }
        return false;
    }
};
