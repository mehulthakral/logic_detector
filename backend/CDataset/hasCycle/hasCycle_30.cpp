/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return false;
    }
    int dup=INT_MAX;
    struct ListNode * temp = head;
    while(temp->next != NULL){
        if(temp->val == dup){
            return true;
        }
        temp->val=dup;
        temp=temp->next;
    }
    return false;
    
    
}
 };
