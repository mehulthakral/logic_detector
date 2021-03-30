    ListNode* reverseList(ListNode* head,ListNode* prev=NULL) {
        if(head==NULL){return prev;}
        ListNode*temp = head->next;
        head->next = prev;
        return reverseList(temp,head);
    }
