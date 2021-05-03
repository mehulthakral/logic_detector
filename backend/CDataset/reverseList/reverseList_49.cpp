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
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* p=NULL;
        ListNode* q=head;
        ListNode* r=q->next;
        while(q!=NULL){
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        head=p;
        return head;
    }
};
