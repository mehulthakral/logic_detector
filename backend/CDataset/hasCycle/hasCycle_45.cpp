class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {return false;}
        if (head -> val == -12345) {return true;}
        
        head -> val = (head -> val) * 0 - 12345;
        bool statement;
        statement = hasCycle(head -> next);
        return statement;
    }
};
