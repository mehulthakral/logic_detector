    static constexpr bool hasCycle(const ListNode * const head)
    {
	    // Return early if the list is too short to have a cycle:
        if(!head || !head->next){
            return false;
        }
        
        const ListNode * it = head->next;
        const ListNode * it2 = head;
        while(it != nullptr){
            if(it == it2) return true;
            it = it->next;
            if(it == nullptr) return false;
            if(it == it2) return true;
            it = it->next;
            it2 = it2->next;
        }

        return false;
    }
