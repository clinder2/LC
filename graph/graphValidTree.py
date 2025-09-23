from collections import deque
class Solution:
    def bfs(self, i, adj, n):
        q=deque()
        q.append(i)
        seen={i: 0 for i in range(n)}
        count=0
        while len(q):
            curr=q.popleft()
            count+=1
            seen[curr]=1
            if curr in q:
                return 0
            for j in adj[curr]:
                if seen[j]!=1:
                    q.append(j)
        return count

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)!=n-1:
            return False
        adj=[[] for _ in range(n)]
        for e in edges:
            adj[e[0]].append(e[1])
            adj[e[1]].append(e[0])
        seen={i: 0 for i in range(n)}
        count=self.bfs(0, adj, n)
        if count!=n:
            return False
        return True