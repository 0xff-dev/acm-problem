# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root: TreeNode):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return root
        def inner_func(root: TreeNode):
            root.left, root.right = root.right, root.left
            if root.left is not None:
                self.invertTree(root.left)
            if root.right is not None:
                self.invertTree(root.right)
        inner_func(root)
        return root