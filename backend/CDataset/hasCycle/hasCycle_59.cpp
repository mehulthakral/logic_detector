class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        //p1 move two steps every time, p2 move one step every time 
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1 != nullptr){
            p2 = p2->next;
            p1 = p1->next;
            if(p1) p1 = p1->next;
            if(p1 && p1 == p2) return true;
        }        
        return false;
    }
 };
