class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        v[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            v[i]=v[i-1]+nums[i];
        }
        int l = 0;
        int r = v.back();
        int m = (l+r)/2;
        int ans = 0;
        while (l<=r) {
            m=(l+r)/2;
            if (good(m, k, v)) {
                r=m-1;
                ans=m;
            } else {
                l=m+1;
            }
        }
        return ans;
    }
    bool good(int m, int k, vector<int> v) {
        int prev=0;
        int i = 0;
        while (i<v.size() && k>0) {
            int old=i;
            while (i<v.size() && v[i]-prev<=m) {
                i++;
            }
            if (i==old) {
                return false;
            }
            prev=v[i-1];
            k--;
        }
        if (i<v.size() && k<=0) {
            return false;
        }
        return true;
    }
};