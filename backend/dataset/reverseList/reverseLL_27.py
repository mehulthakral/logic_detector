class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        curr = head
        while curr:
            temp = curr.next #取出原list里的下一个元素，防止弄丢

            curr.next = pre #将当前指针的下一个指向之前的元素，在第一次运行时之前的元素为None
            pre = curr #这一次的当前元素就是下一次的之前的元素
        
            curr = temp #把指向当前元素的指针指到最开始存到temp里的下一个元素上
        return pre #跳出循环时，curr是none，上一个循环里的curr即pre才是新链表的头
