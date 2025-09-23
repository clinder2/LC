class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        ans=[]
        roll=0
        n=len(nums)
        a=min(k,len(nums))
        for i in range(a):
            roll+=nums[i]
        for i in range(len(nums)):
            #roll+=nums[i]
            if i<k:
                if i+k<n:
                    roll+=nums[i+k]
                ans.append(-1)
            elif i>len(nums)-k-1:
                ans.append(-1)
            else:
                roll+=nums[i+k]
                ans.append(roll//(2*k+1))
                roll-=nums[i-k]
        return ans