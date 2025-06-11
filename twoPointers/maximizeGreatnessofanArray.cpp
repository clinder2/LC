class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int r = 0;
        while (r<nums.size()&&nums[r]==nums[0]) {
            r++;
        }
        int l = 0;
        int ans = 0;
        while (r<nums.size()) {
            if (nums[r]>nums[l]) {
                ans++;
                r++;
                l++;
            } else {
                r++;
            }
        }
        return ans;
    }
};