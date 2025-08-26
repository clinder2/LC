class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        int count=0;
        for (auto i : nums) {
            m[i]+=1;
            count+=i;
        }
        int ans=-1000;
        for (int i = 0; i < nums.size(); i++) {
            if ((count-nums[i])%2==0 && m[(count-nums[i])/2]) {
                if ((count-nums[i])/2 != nums[i]) {
                    ans=max(ans,nums[i]);
                } else if (m[nums[i]]>1) {
                    ans=max(ans,nums[i]);
                }
            }
        }
        return ans;
    }
};