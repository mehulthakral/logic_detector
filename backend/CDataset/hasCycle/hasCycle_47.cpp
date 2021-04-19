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

    bool hasCycle(ListNode *head) 
    {
        if(head==NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        bool ans=false;
        while(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast->next==NULL) return false;
            fast = fast->next;
            if(fast==slow) 
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};
