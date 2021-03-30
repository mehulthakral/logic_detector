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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head,*prev=NULL,*q; //
        
        while(cur!=NULL){
            q=cur->next; // storing next pointer to modifiy it leater
            cur->next=prev;  // Reversing the pointer to the prev
            prev=cur;  // make the prev equal to the last node we added
            cur=q; // we get the value back from q that we stored at the first of the loop
        }
        return prev; /// return the ans
    }
    
};
      
