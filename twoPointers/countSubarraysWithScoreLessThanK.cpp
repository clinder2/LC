class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int l = 0;
        int r = 0;
        long long prev=0;
        while (r<nums.size()) {
            if (nums[r]>=k) {
                r++;
                l=r;
                prev=0;
            } else {
                prev+=nums[r];
                while ((r-l+1)*prev>=k && l<r) {
                    prev-=nums[l++];
                }
                ans+=r-l+1;
                r++;
            }
        }
        return ans;
    }
};