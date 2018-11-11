# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return_head = head
        pre = None
        is_first =True
        while head is not None and head.next is not None:
            node = head.next
            head.next = node.next
            node.next = head
            if is_first:
                return_head = node
                is_first = False
            if pre is not None:
                pre.next = node
            pre = head
            head = head.next
        return return_head

def generate(nums: list):
    head = ListNode(nums[0])
    p = head
    for i in nums[1:]:
        p.next = ListNode(i)
        p = p.next
    return head

def out(head):
    while head is not None:
        print(head.val)
        head = head.next

obj = Solution()
nums = [2, 5, 3, 4, 6, 2, 2]
num1 = [1, 2, 3, 4]
head1 = generate(num1)
head = generate(nums)
out(head)
out(head1)
print('RES1')
out(obj.swapPairs(head1))
print("RES2")
out(obj.swapPairs(head))
