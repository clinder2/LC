class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int l=0,r=0;
        int curr=1;
        while (r<nums.size()) {
            curr*=nums[r];
            if (curr<k) {
                ans+=r-l+1;
            } else {
                while (l<r && curr>=k) {
                    curr/=nums[l++];
                }
                if (curr<k) {
                    ans+=r-l+1;
                }
            }
            r++;
        }
        return ans;
    }
};