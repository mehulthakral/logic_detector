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
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL) return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast!=NULL && slow!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL) fast = fast->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
