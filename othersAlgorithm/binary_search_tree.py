class Node(object):
    def __init__(self, value):
        self.value = value
        self.parent = None
        self.left = None
        self.right = None

    def __str__(self):
        return f'<Node {self.value}>'

    __repr__ = __str__


class BinarySearchTree(object):
    def __init__(self):
        self.root = None
    
    def insert(self, value: int):
        def __insert(root: Node, value: int):
            if root is None:
                root = Node(value)
            else:
                if root.value > value:
                    __insert(root.left, value)
                elif root.value < value:
                    __insert(root.right, value)
                else:
                    raise ValueError(f'Value<{value}> exist in tree')
        __insert(self.root, value)

    def pre_travel(self, recursive: bool=False):
        """
        是否进行递归遍历
        """
        if recursive:
            def __pre_travel(root: Node):
                if root is None:
                    return
                print(root.value)
                if root.left is not None:
                    __pre_travel(root.left)
                if root.right is not None:
                    __pre_travel(root.right)
            __pre_travel(self.root)
        else:
           res = []
           p = self.root
           while p is not None or len(res)>0:
                while p is not None:
                    print(p.value)
                    res.append(p)
                    p = p.left
                if len(res)>0:
                    tmp_node = res[-1]
                    res.pop()
                    p = tmp_node.right

    def inorder_travel(self, recursive: bool=False):
        """
        中序遍历
        """
        if recursive:
            def __inorder_travel(root: Node):
                if root.left is not None:
                    __inorder_travel(root.left)
                print(root.value)
                if root.right is not None:
                    __inorder_travel(root.right)
            __inorder_travel(self.root)
        else:
            res = []
            p = self.root
            while p is not None or len(res) > 0:
                while p is not None:
                    res.append(p)
                    p = p.left
                if len(res)>0:
                    p = res[-1]
                    print(p.value)
                    res.pop()
                    p = p.right

    def postorder_travel(self):
        """
        后序遍历, 递归后序再补, 还没看
        """
        def __postorder_travel(root: Node):
            if root.left is not None:
                __postorder_travel(root.left)
            if root.right is not None:
                __postorder_travel(root.right)
            print(root.value)

    def floor_travel(self):
        """
        层遍历
        """
        queue = [self.root]
        while len(queue) > 0:
            _tmp_queue = []
            for item in queue:
                print(item, end=' ')
                if item.left is not None:
                    _tmp_queue.append(item.left)
                if item.right is not None:
                    _tmp_queue.append(item.right)
            print()
            queue = _tmp_queue

    def _find_parent(root: Node, value: int, predecessor: bool=True) -> Node:
        # 有父节点的时候, 直接使用递归即可
        if predecessor:
            parent = node.parent
            while parent is not None and parent.right != node:
                node = parent
                parent = node.parent
            return parent
        else:
            parent = node.parent
            while parent is not None and parent.left != node:
                node = parent
                parent = node.parent
            return parent

    def find_parent(self, predecessor: bool=True, value: int):
        """
        找前驱或者后继节点, 在节点里没有parent选项的时候
        """
        root = self.root
        p, first_parent, node = None, None, None
        if predecessor:
            while root:
                if root.value == value:
                    return node, p, first_parent
                p = root
                if root.value > value:
                    root = root.left
                else:
                    first_parent = root
                    root = root.right
            return None
        else:
            while root:
                if root.value == value:
                    return node, p, first_parent
                p = root
                if root.value < value:
                    root = root.right
                else:
                    first_parent = root
                    root = root.left
            return None

    def get_node(self, root: Node, is_left: bool=True):
        """
        找一个节点的左子树的右节点, 或者右子树扽左节点
        """
        if is_left:
            while node.right is not None:
                node = node.right
            return node
        else:
            while node.left is not None:
                node = node.left
            return node

    def predecessor(self, value: int):
        """
        找前驱节点
        """
        node, p, fp = self.find_parent(value=value)
        if node is None:
            return None
        if node.left is not None:
            return self.get_node(node, True)
        elif p is None of fp is None:
            return None
        elif node == p.right:
            return p
        return fp

    def successor(self, value: int):
        """
        找后继
        """
        node, p, fp = self.find_parent(False, value=value)
        if node is None:
            return None
        if node.right is not None:
            return self.get_node(node, False)
        elif p is None or fp is None:
            return None
        elif node == p.left:
            return p
        return fp
