
class Solution {
    ListNode* reverseL(ListNode* cur,ListNode** newhead) {    // using ** so that change remain permanent(similar to call by reference)
        if(cur->next==NULL){       // base case and also for "[1]" case
             *(newhead)=cur;       // new head
            return cur;
        }
        else{
        ListNode* n = reverseL(cur->next,newhead);
        n->next=cur;
        return cur;
        }
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)          // for [] case
            return head;
        ListNode* temp =head;
        ListNode* t = reverseL(head,&temp);
        t->next=NULL;       // head = tail
        return temp;            // returning the new head
    }
};
