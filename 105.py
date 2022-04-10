from typing import List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        
        inorder_idx = inorder.index(preorder[0])

        root.left = self.buildTree(preorder[1:inorder_idx+1], inorder[:inorder_idx])
        root.right = self.buildTree(preorder[inorder_idx+1:], inorder[inorder_idx+1:])
        
        return root