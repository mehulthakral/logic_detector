class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * current = head;
        ListNode * previous = nullptr;
        ListNode * next = nullptr;
        
        // 1 -> 2 -> 3 -> nullptr
        while (current != nullptr) {
            // store the next of current and change its value so that it points to previous
            next = current -> next;
            // previous(nullptr) <- 1  2 -> 3 -> nullptr
            current -> next = previous;
            
            // Settings for the next iteration
            
            // the current will be the previous of next of current
            previous = current;
            // move current to its next stored in the first step
            current = next;
        }
        // we are doing this iteration for all the elements in the loop
        
        // In the end, our current will point to nullptr(past the list)
        // and our previous will point to the last node, which for us
        // is the first node of the reversed list
        
        // nullptr <- 1 <- 2 <- 3 
        
        return previous;
    }
};
