/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* headprev=head;
        head=head->next;
        headprev->next=NULL;
        ListNode* headnew;
        while(head!=NULL)
        {
            headnew=head;
            head=head->next;
            headnew->next=headprev;
            headprev=headnew;
        }
        return headnew;
    }
};
