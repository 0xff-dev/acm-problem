"""
用链表做加法
比如
1->2->3->4->5 + 2->3->4 = 1->2->5->7->9
"""

from random import randint

class Node(object):

    def __init__(self, v):
        self.v = v
        self.next = None

    def __str__(self):
        return str(self.v)


class LinkList(object):
    """
    为了方便测试, 数据都是随机生成的, 暂时还没有考虑前导0的问题, 
    所有数据都在1-9范围之内
    """
    def __init__(self):
        self.root1, self.root2 = self.generate()
        self.printf(self.root1)
        self.printf(self.root2)

    def generate(self):
        root1 = Node(randint(1, 9))
        root2 = Node(randint(1, 9))
        p, q = root1, root2
        for i in range(randint(1, 8)):
            node = Node(randint(1, 9))
            p.next = node
            p = node
        for i in range(randint(1, 8)):
            node = Node(randint(1, 9))
            q.next = node
            q = node
        return root1, root2

    def printf(self, root: Node):
        p = root
        while p is not None:
            print(p, end='')
            p = p.next
        print()

    def reverse(self, root: Node):
        if root is None:
            return None
        p, q = root, root.next
        p.next = None
        count = 1
        while q is not None:
            tmp = q.next
            q.next = p
            p = q
            q = tmp
            count += 1
        print('RES: ', end='')
        self.printf(p)
        print('Node: {}'.format(count))
        return p, count

    def add(self):
        head1, h1_count = self.reverse(self.root1)
        head2, h2_count = self.reverse(self.root2)
        res = []
        max_head, min_head = head1, head2
        pre_node = None
        if h2_count > h1_count:
            max_head, min_head = min_head, max_head
        reverse_node = max_head
        cf = 0
        while max_head is not None and min_head is not None:
            _tmp_sum = max_head.v + min_head.v + cf
            cf = _tmp_sum // 10
            _tmp_sum %= 10
            max_head.v = _tmp_sum
            pre_node = max_head
            max_head = max_head.next
            min_head = min_head.next
        while max_head is not None:
            _tmp_sum = max_head.v + cf
            cf = _tmp_sum // 10
            _tmp_sum %= 10
            max_head.v = _tmp_sum
            pre_node = max_head
            max_head = max_head.next
        if cf != 0:
            node = Node(cf)
            pre_node.next = node
            pre_node = node
        root, count = self.reverse(reverse_node)
        self.printf(root)
 

if __name__ == '__main__':
    link_list = LinkList()
    link_list.add()
