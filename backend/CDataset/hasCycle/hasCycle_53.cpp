class Solution {
public:
    bool hasCycle(ListNode *head) {
        // support variables
		ListNode *turtle = head;
		// let the race begin!
        while (head && head->next) {
            head = head->next->next;
            turtle = turtle->next;
			// cycle detected
            if (head == turtle) return true;
        }
        return false;
    }
};
