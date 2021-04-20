class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };
    ListNode* reverseList(ListNode* head) {
        queue <ListNode*> list_stack;
        auto pointer = head;
        ListNode* res = nullptr;
        while (pointer)
        {
            list_stack.push(pointer);
            pointer = pointer -> next;
        }
        
        while (!list_stack.empty())
        {
            auto current = res;
            res = list_stack.front();
            res -> next = current;
            list_stack.pop();
        }
        

        
        return res;
    }
};