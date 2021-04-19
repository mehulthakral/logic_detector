class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    
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

