class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        a=[]
        t=0
        for i in range(0,len(arr)):
            t=t+arr[i]
            a.append(t)
        even=0
        odd=0
        ans=0
        for i in a:
            if i%2==1:
                odd=odd+1
                ans=(ans+even+1)%1000000007
            else:
                even=even+1
                ans=(odd+ans)%1000000007
        return ans%1000000007