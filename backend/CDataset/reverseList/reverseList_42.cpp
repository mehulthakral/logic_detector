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

    ListNode* util(ListNode* prev, ListNode* cur, ListNode* next) {
        if(cur==NULL)
            return prev;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        return util(prev,cur,next);
    }
    ListNode* reverseList(ListNode* head) {
        auto o = util(NULL,head,NULL);
        return o;
    }
};
