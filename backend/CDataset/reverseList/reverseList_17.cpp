class Solution {
public:

    class ListNode{
        public:
        ListNode* next;
        int val;
    };

ListNode* reverseList (ListNode *head) 
    {
        // traverse the head, and add every node to a new list starting from the end

        // if head is empty, return null
        if (head == 0)
            return 0;
        // create a node that receives the first value of head and points to null (end
        // of the list)
        ListNode *reversed = new ListNode(head->val);
        // go to the next node on head
        head = head->next;
        // now we might loop because adding the other nodes use the same proccess
        // while we did not reach the end of the head
        while (head != 0)
        {
            // creates a new node with the current head->val and points to the former
            // reversed node. Note that this is a pointer assignment, so reversed is
            // updated
            reversed = new ListNode(head->val, reversed);
            // go to next node on head
            head = head->next;
        }
        // reversed already points to the beggining of the reversed list
        return reversed;
    }
};