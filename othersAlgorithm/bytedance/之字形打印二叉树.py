class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def Print(self, pRoot):
        flag = 0
        queue = [pRoot]
        res = []
        while len(queue) > 0:
            tmp_queue = []
            tmp_store = []
            length = len(queue)-1
            if flag == 0:
                for item in range(length, -1, -1):
                    tmp_store.append(queue[length-item].val)
                    if queue[item].right is not None:
                        tmp_queue.append(queue[item].right)
                    if queue[item].left is not None:
                        tmp_queue.append(queue[item].left)
            else:
                for item in range(length+1):
                    tmp_store.append(queue[item].val)
                    if queue[length-item].left is not None:
                        tmp_queue.append(queue[length-item].left)
                    if queue[length-item].right is not None:
                        tmp_queue.append(queue[length-item].right)
            flag = 1 - flag
            queue = tmp_queue
            res.append(tmp_store)
        return res            

s = Solution()
tree = Node(8)
tree.left = Node(6)
tree.left.left = Node(5)
tree.left.right = Node(7)
tree.right = Node(10)
tree.right.left = Node(9)
tree.right.right = Node(11)
print(s.Print(tree))