
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* first;
        ListNode* p;
        vector<ListNode*>tab;
        p=head;
        while(p->next!=nullptr){
            tab.push_back(p);
            p=p->next;
        }    
        first=p;
        int n=tab.size();
        for(int i=n-1;i>=0;i--){
            p->next=tab[i];
            p=tab[i];
        }
        p->next=nullptr;
        return first;
        
    }
};
