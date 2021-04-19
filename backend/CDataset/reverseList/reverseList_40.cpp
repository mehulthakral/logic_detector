/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class ListNode{
        public:
        ListNode* next;
        int val;
    };

    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        stack<int> st;
        st.push(head->val);
        while(head->next!=NULL)
            st.push(head->next->val), head=head->next;
        ListNode* t = new ListNode(st.top());
        head = t;
        while(!st.empty()) {
            st.pop();
            if(st.size())
                t->next = new ListNode(st.top()), t=t->next;
        }
        return head;
    }
};
