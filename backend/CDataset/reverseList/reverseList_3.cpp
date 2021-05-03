class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) 
        {
            return head;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = nullptr;
        
        while(p1!=nullptr)
        {
            p1 = p1->next;
            head->next = p2;
            p2 = head;
            head = p1;
        }
        
        return p2;
    }
};
