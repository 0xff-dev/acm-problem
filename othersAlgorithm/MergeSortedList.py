Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 归并的问题
        res = []
        while l1 is not None:
            res.append(l1)
            l1 = l1.next
        while l2 is not None:
            res.append(l2)
            l2 = l2.next
        if len(res) == 0:
            return None
        sorted(res, key=lambda x: x.val)
        for i in range(1, len(res)):
            res[i-1].next = res[i]
        res[-1].next = None
        return res[0]

