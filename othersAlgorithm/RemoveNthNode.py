# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # 隔步数, 开头和结尾的节点相聚n
        index = 0
        node = h_node = head
        while index<n-1:
            node = node.next
            index += 1
        # 找到起点
        if node.next == None:
            return head.next
        head_pre = None
        while node.next is not None:
            head_pre = head
            head = head.next
            node = node.next
        head_pre.next = head.next
        return h_node