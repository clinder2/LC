"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def rec(self, grid):
        temp=sum(sum(r) for r in grid)
        if temp!=0 and temp!=len(grid)**2:
            a=int(len(grid)/2)
            #print([grid[i][a:] for i in range(a)])
            n=Node()
            n.isLeaf=False
            n.val=True
            n.topLeft=self.rec([grid[i][:a] for i in range(a)])
            n.topRight=self.rec([grid[i][a:] for i in range(a)])
            n.bottomLeft=self.rec([grid[i][:a] for i in range(a,2*a)])
            n.bottomRight=self.rec([grid[i][a:] for i in range(a,2*a)])
            return n
        else:
            n=Node()
            n.isLeaf=True
            if temp:
                n.val=True
            else:
                n.val=False
            return n

    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.rec(grid)
