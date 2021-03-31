ListNode* dfs(ListNode* head, ListNode* prev) {
		if (head == nullptr)
			return prev; // search for the last node of the list
			
        ListNode* root = dfs(head->next, head);  // get last node of the list
        head->next = prev; // change current node next pointer to prev node
        
        return root; // return last node of the original list (will be first now)
    }
    
    ListNode* reverseList(ListNode* head) {
       return dfs(head, nullptr);
    }

