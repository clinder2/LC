class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> l(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            l[i]=(nums[i]+nums[i-1])%2==0 ? l[i-1]+1 : l[i-1];
        }
        vector<bool> ans(queries.size());
        int i =0;
        for (auto q : queries) {
            if (l[q[0]]==l[q[1]]) {
                ans[i]=true;
            } else {
                ans[i]=false;
            }
            i++;
        }
        return ans;
    }
};