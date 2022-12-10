# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.root = root
        self.sum = self.get_sum(root)
        self.max = 0
        self.get_max(root)
        return self.max % (10**9+7)

    def get_sum(self, node) -> int:
        if not node:
            return 0
        return node.val + self.get_sum(node.left) + self.get_sum(node.right)

    def get_max(self, node) -> int:
        if not node:
            return 0

        cur_sum = node.val + self.get_max(node.left) + self.get_max(node.right)
        self.max = max(self.max, cur_sum * (self.sum - cur_sum))
        return cur_sum
