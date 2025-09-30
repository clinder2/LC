class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        l=[[spells[i],i] for i in range(len(spells))]
        l.sort()
        potions.sort()
        r=len(potions)-1
        s=0
        while r-1>=0 and potions[r]*l[s][0]>=success:
            r-=1
        ans=len(spells)*[0]
        if potions[r]*l[s][0]>=success:
            ans[l[0][1]]=len(potions)-r
        else:
            ans[l[0][1]]=len(potions)-r-1
        for i in range(1,len(l)):
            while r-1>=0 and potions[r]*l[i][0]>=success:
                r-=1
            if potions[r]*l[i][0]>=success:
                ans[l[i][1]]=len(potions)-r
            else:
                ans[l[i][1]]=len(potions)-r-1
        return ans