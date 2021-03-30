/*
Runtime: 12 ms, faster than 68.90% of C++ online submissions for Linked List Cycle.
Memory Usage: 8 MB, less than 16.16% of C++ online submissions for Linked List Cycle.

Reference Video : https://www.youtube.com/watch?v=MFOAbpfrJ8g
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)
            return false;
        ListNode *a = head->next;
        ListNode *b = head;
        while(a!=nullptr && b!=nullptr && a->next!=nullptr){
            if(a==b)
                return true;
            a = a->next->next;
            b = b->next;
        }
        return false;
    }
};
