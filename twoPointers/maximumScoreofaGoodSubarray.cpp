class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> in = {k>0 ? nums[k-1] : -1, k<nums.size()-1 ? nums[k+1] : -1};
        int ans = nums[k];
        int len = 1;
        int l=k-1;
        int r = k+1;
        int m = nums[k];
        while (len<nums.size()) {
            if (in[0]>in[1]) {
                m=min(m,in[0]);
                l--;
                ans=max(ans,(len+1)*m);
                in[0] = l>=0 ? nums[l] : -1;
            } else {
                m=min(m,in[1]);
                r++;
                ans=max(ans,(len+1)*m);
                in[1] = r<nums.size() ? nums[r] : -1;
            }
            len++;
        }
        return ans;
    }
};