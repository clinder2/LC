class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        m={}
        for i in time:
            m[i%60]=0
        for i in time:
            m[i%60]+=1
        ans=0
        for k in m.keys():
            curr=(60-k)%60
            if curr in m.keys():
                ans+=m[k]*m[curr]
            if curr==k:
                ans-=m[k]
        return int(ans/2)