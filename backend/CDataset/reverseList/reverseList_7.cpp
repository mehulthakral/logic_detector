class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head,*prev=NULL,*q;
        
        while(cur!=NULL){
            q=cur->next; // storing next pointer
            cur->next=prev;  // Reversing the pointer
            prev=cur; 
            cur=q;
        }
        return prev;
    }
    
};
