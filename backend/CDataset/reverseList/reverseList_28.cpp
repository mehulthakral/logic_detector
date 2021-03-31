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
        //return iterative(head);
        return recursive(head, NULL);
    }
    //RECURSIVE SOLUTION
    ListNode* recursive(ListNode* head, ListNode* res){
        //test if head is NULL and list has ended
        if(head==NULL) return res;
        //set new list node for result with value from head
        ListNode* prev=new ListNode(head->val);
        //add the new list node BEFOR the previouse list node
        prev->next=res;
        return recursive(head->next, prev);
    }
    //ITERATIVE SOLUTION
    ListNode* iterative(ListNode* head){
        ListNode* prev=NULL;
        //go through linked list
        while(head!=NULL){
            //set new list node for result with value from head
            ListNode* current=new ListNode(head->val);
            //add the new list node BEFOR the previouse list node
            current->next=prev;
            //set previouse node to current list node
            prev=current;
            head=head->next;
        }
        return prev;
    }
};
