class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        ma=0
        mi=100000
        total=0
        for i in differences:
            total+=i
            ma=max(ma,total)
            mi=min(mi,total)
        ans=0
        if mi>0:
            mi=0
        temp=upper-(ma+abs(mi))
        return temp-lower+1 if temp-lower+1>0 else 0