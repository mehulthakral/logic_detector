class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while(head){
            if(seen.find(head)!=seen.end()) return true;
            seen.insert(head);
            head=head->next;
        }
        return false;
		} 
};