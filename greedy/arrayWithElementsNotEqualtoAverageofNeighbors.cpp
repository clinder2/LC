class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i = 0;
        int j = nums.size()-1;
        while (i<j) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j--]);
        }
        if (i==j) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};