class Node(object):
    def __init__(self, value):
        self.value = value
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
        pass

    def inorder_travel(self, recursive: bool=False):
        """
        中序遍历
        """
        pass

    def postorder_travel(self):
        """
        后序遍历, 递归后序再补, 还没看
        """
        pass

    def floor_travel(self):
        """
        层遍历
        """
        pass

    def find_parent(self, predecessor: bool=True):
        """
        找前驱或者后继节点, 在节点里没有parent选项的时候
        """
        pass

    def get_node(self, root: Node, is_left: bool=True):
        """
        找一个节点的左子树的右节点, 或者右子树扽左节点
        """
        pass
    
    def predecessor(self, value: int):
        """
        找前驱节点
        """
        pass

    def successor(self, value: int):
        """
        找后继
        """
        pass
