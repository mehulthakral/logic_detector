class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if(head ==nullptr || head->next == nullptr)
            return head;
        
        ListNode* rest = head->next;
        ListNode* reversed = head;
        reversed->next = nullptr;
       
        
        while(rest)
        {
            ListNode* tmp = rest;
            rest = rest->next;
            tmp->next = reversed;
            reversed = tmp;
        }
    
        return reversed;
    }
};
