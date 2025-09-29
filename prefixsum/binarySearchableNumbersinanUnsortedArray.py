class Solution:
    def binarySearchableNumbers(self, nums: List[int]) -> int:
        n=len(nums)
        left=n*[0]
        right=n*[0]
        left[0]=nums[0]
        right[-1]=nums[-1]
        for i in range(1,n):
            left[i]=max(left[i-1],nums[i])
            right[n-1-i]=min(right[n-i],nums[n-1-i])
        ans=0
        for i in range(n):
            if nums[i]>=left[i] and nums[i]<=right[i]:
                ans+=1
        return ans