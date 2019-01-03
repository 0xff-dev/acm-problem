from random import randint


class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None

    def __str__(self):
        return f'<Node> -> {self.value}'

    __repr__ = __str__


class LinkList(object):
    def __init__(self, nums: list):
        self.head = None
        opt = input("是否逆序构造(y/n)")
        if opt == 'y':
            for item in nums:
                node = Node(item)
                node.next = self.head
                self.head = node
        else:
            p = self.head
            for item in nums:
                node = Node(item)
                if p is None:
                    p = node
                    self.head = node
                else:
                    node.next = p.next
                    p.next = node

    def reverse(self):
        """
        反转链表
        """
        print('Reverse')
        p, q = self.head, self.head.next
        p.next = None
        while q is not None:
            tmp = q.next
            q.next = p
            p = q
            q = tmp
        self.head = p

    def sort(self):
        print('Sort')
        def _sort(head: Node, end=None):
            if head ==end or head.next == end:
                return
            aim = head
            p, q = head, head.next
            while q != end:
                if q.value < aim.value:
                    p = p.next
                    p.value, q.value = q.value, p.value
                q = q.next
            p.value, head.value = head.value, p.value
            _sort(head, p)
            _sort(p.next, end)
        _sort(self.head, None)

    def display(self):
        p = self.head
        while p is not None:
            print(p, end=' ')
            p = p.next
        print()

    def has_cycle(self) -> tuple:
        """
        判断链表是否有环
        :return:
        """
        p, q = self.head, self.head.next
        while q is not None and q.next is not None and q != p:
            q = q.next.next
            p = p.next
        if q != p:
            return False, "doest not has cycle"
        tmp = self.head
        while tmp != p:
            tmp = tmp.next
            p = p.next
        return tmp, "入口"


if __name__ == '__main__':
    ll = LinkList([randint(1, 30) for i in range(randint(3, 10))])
    ll.display()
    ll.reverse()
    ll.display()
    ll.sort()
    ll.display()
    print(ll.has_cycle())