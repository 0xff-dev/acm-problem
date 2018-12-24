class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def __str__(self):
        return f'<Node {self.value}>'

    __repr__ = __str__
    

class BinaerTree(object):
    def __init__(self):
        self.root = Node('A')
        self.root.left = Node('B')
        self.root.right = Node('C')
        self.root.left.left = Node('D')
        self.root.left.right = Node('E')
        self.root.left.right.right = Node('G')
        self.root.right.left = Node('F')

    def floor_travel(self):
        queue = [self.root]
        while len(queue) > 0:
            _tmp_queue = []
            for item in queue:
                print(item , end=' ')
                if item.left is not None:
                    _tmp_queue.append(item.left)
                if item.right is not None:
                    _tmp_queue.append(item.right)
            print()
            queue = _tmp_queue

if __name__ == '__main__':
    bt = BinaerTree()
    bt.floor_travel()