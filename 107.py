from typing import List
from queue import Queue
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        layer_traverse = []
        if not root:
            return layer_traverse
        
        q = Queue()
        
        q.put(root)

        while q.qsize():
            layer = []
            p = Queue()
            while q.qsize():
                node = q.get()
                layer.append(node.val)
                if node.left:
                    p.put(node.left)
                if node.right:
                    p.put(node.right)
            layer_traverse.append(layer)
            q = p
        
        return sum(layer_traverse[::-1], [])