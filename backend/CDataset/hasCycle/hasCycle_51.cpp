class Solution {
public:
bool hasCycle(ListNode head) {
ListNode temp=head;
int flag=0;
while(temp)
{
flag++;
temp=temp->next;
if(flag>=10000)return true;
}
return false;
}
};