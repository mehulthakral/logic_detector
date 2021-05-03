class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        
		// BASE CASE
        // if the linked list is empty or has only one node, we are done!
        if (head == nullptr or head -> next == nullptr) {
            return head;
        }
        
		// INDUCTION
        // 1 -> 2 -> 3 -> nullptr
        // use Recursive leap of faith to reverse the rest of the list
        ListNode * reverse = reverseList(head -> next);
        
        // we got:
        
        //    nullptr
        //      ^
        //      |
        // 1 -> 2 <- 3
        // reverse pointer is actually pointing to 3
        
		// HYPOTHESIS
        // Now that we have our reversed list EXCLUDING the first node
        // we want 2's next to point to 1
        // therefore, we can set the next of (next of 1 (which is 2)) to 1, itself
        ListNode * secondLast = head -> next;
        secondLast -> next = head;  // as head is the last node in the reversed list(as it was first in our original list) and put nullptr in its next as the next step
        head -> next = nullptr;
        return reverse;
    }
};
