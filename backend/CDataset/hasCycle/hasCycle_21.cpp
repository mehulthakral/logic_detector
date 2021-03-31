class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*h1=head;
        ListNode*h2=head;
        while(h1 && h2 && h2->next){
            h1=h1->next;
            h2=h2->next->next;
            if(h1==h2)
                return true;
        }
        return false;
        
    }
};
