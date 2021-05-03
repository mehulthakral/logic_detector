static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();
class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(head->next!=NULL and head->next->val==INT_MAX) return true;
            head->val = INT_MAX;
            head=head->next;
        }
        return false;
    }
};
