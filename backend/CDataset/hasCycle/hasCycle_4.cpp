/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* rabit = head;
        ListNode* turtle = head;
        while (rabit->next != NULL && rabit->next->next != NULL) {
            turtle = turtle->next;
            rabit = rabit->next->next;
            if (rabit == turtle) return true;
        }
        return false;
    }
};
