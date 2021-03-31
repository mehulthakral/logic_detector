class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* prev = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return prev;
    }
};
