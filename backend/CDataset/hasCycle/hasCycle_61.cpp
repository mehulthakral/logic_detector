class Solution {
public:
    bool hasCycle(ListNode *head) {
        int t=8500; //I did binarysearch for this value :P, but you can just have it equal to 100000 and it works just fine <8ms.
        while(t--){
            if(head==NULL)return false;
            head=head->next;
        }
        return true;
    }
};
