class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        m={}
        seen={}
        for c in regions:
            for i in range(1,len(c)):
                m[c[i]]=c[0]
        p=m[region1]
        seen[region1]=1
        while p in m.keys():
            seen[p]=1
            p=m[p]
        seen[p]=1
        p=region2
        while p in m.keys():
            if p in seen.keys():
                return p
            p=m[p]
        return p