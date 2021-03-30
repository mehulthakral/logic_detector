class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *a = head;
		
//         unordered_map<ListNode*, int> hash;
//         while (a) {
//             if (hash.find(a) != hash.end()) return true;
//             a = a->next;
//         }
//         return false;
        
        ListNode* fast = head;
        
        while (fast && a && fast->next) {
            a = a->next;
            fast = fast->next->next;
            if (fast == a) return true;
        }
        return false;
    }
};
