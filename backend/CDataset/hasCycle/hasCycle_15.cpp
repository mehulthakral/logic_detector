class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    
    bool hasCycle(ListNode *head) {
        auto p = head;
        if(!p) return false;
        int c = 2;
        int lim = c;
        for(auto k = head->next; k != NULL; k = k->next) {
            if (k == p) 
                return true;
            if(--c == 0) {
                lim = lim * 5;
                c = lim;
                p = k;
            }
        }
        return false;
    }
};