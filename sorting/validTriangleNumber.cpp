class Solution {
public:
    int ans=0;
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int r = 1; r < nums.size(); r++) {
                for (int l = 0; l < r; l++) {
                    int k=r+1;
                    while(k<nums.size()&&nums[k]<nums[l]+nums[r]) {
                        k++;
                    }
                    ans+=k-r-1;
                }
        }
        return ans;
    }
};