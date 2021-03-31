class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *slow=head;
        ListNode *fast;
        
        if(slow)
            fast=head->next; // "fast" can also start from the same node as "slow"
        else
            return false;
        
        while(slow||fast){  // while traversing if both of them becomes NULL together, no cycle found
			
            if(slow==fast) // then we got the same node again, hence cycle found
                return true; // [ CASE 1 ]
            
            if(slow)
                slow=slow->next; // move 1 step at a time
            
            if(fast){
                if(fast->next)
                    fast=fast->next->next; // move 2 step at a time
                else
                    break; // if 2 step jump not possible at any node then break from loop, hence no cycle
            }
        }
        // [ CASE 2 ]
        return false; // no cycle found at this point
    }
};
