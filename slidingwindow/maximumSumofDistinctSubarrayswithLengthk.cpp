class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        long long curr=0;
        long long ans=0;
        int count=0;
        for (int i = 0; i < k; i++) {
            curr+=nums[i];
            if (m[nums[i]]) {
                count--;
            }
            count++;
            m[nums[i]]++;
        }
        if (count==k) {
            ans=curr;
        }
        for (int i = k; i < nums.size(); i++) {
            m[nums[i-k]]--;
            if (!m[nums[i-k]]) {
                count--;
            }
            m[nums[i]]++;
            if (m[nums[i]]==1) {
                count++;
            }
            curr-=nums[i-k];
            curr+=nums[i];
            if (count==k) {
                ans=max(ans,curr);
            }
            //m[nums[i]]++;
        }
        return ans;
    }
};