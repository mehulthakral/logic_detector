class Solution {
public:
ListNode* reverseList(ListNode* head) {
ListNode* nt;
ListNode* prev = NULL;

    ListNode* curr = head;
    
    while(curr!=NULL){
        nt = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = nt;
        
    }
    
    return prev;
}
};