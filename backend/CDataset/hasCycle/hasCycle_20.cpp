class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode*h=head;
        unordered_set<ListNode*>s;
         while (h != NULL) {
         if (s.find(h) != s.end()) 
            return true;   
          s.insert(h); 
          h = h->next;  
         }
      return false;  
    }
};

