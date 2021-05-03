class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr){
            return false;
        }
        ListNode *slow = head, *fast = head;
        while(slow != nullptr && fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
