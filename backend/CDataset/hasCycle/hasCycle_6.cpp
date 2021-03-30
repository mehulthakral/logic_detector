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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp1->next && temp1->next->next){
            temp1=temp1->next->next;
            temp2=temp2->next;
            if(temp2==temp1){
                return true;
            }
            
        }
        return false;
    }
};
