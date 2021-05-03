/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//apporach using fast and slow pointer
class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *slow=head;
         ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
        
        
    }
};
