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
        if(head==NULL || head->next==NULL) return head;
        //Take two nodes one to point and other to traverse with
		ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr->next!=NULL){
		    //Make a temp node to store the current node
            ListNode* temp = curr;
			//Move current to the next node
            curr = curr->next;
			//Reverse the arrow of temp (which was curr) to previous node
            temp->next = prev;
			// Move prev one step forward
            prev = temp;
        }
		//At last reverse the arrow of last node to prev
        curr->next = prev;
		//Return current as head
        return curr;
    }
};
