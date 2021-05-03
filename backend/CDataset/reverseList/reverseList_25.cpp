class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
	//consider prev,curr,next as three boxes beneath 1 2 3 4 5 linked list
	//To reverse the address , first copy what current node is pointing and then assign to its prev node
	//curr stores address of box in list whose link must be reversed.
	//next stores the next node address pointed to by node whose address in curr
	//prev stores the add of last before node visited
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;//copying node add pointed by add in curr
            curr->next = prev;//copying curr node next to prev node
            prev = curr;// the next prev node will be curr node
            curr = next;//next curr node is next node
        }
        return prev;//prev stores last address of last box in the process
    }
};
