// Recursive Using Extra Memory(Queue)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        queue<int> tmp;
        helper(head, tmp);
        return head;
    }
    
    void helper(ListNode* cur, queue<int> &tmp) {
        if (cur == NULL) {
            return;
        }
        tmp.push(cur->val);
        helper(cur->next, tmp);
        cur->val = tmp.front();
        tmp.pop();
    }
};