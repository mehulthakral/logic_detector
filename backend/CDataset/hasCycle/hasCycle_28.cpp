class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> m;
        while(head!=NULL)
        {
            if(m.find(head)==m.end())
                m.insert(head);
            else
                return 1;
            head=head->next;
        }
        return 0;
    }
};
