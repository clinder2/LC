class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size()<2) return false;
        unordered_map<int,bool> seen1;
        unordered_map<int,int> seen;
        int r=0;
        int zerocount=0;
        bool s=false;
        int i=0;
        for (auto n : nums) {
            if (n) {
                s=true;
                zerocount=0;
                r=(r+n)%k;
                if (r==0 && i>=1) return true;
                if (seen1[r] && i-seen[r]>=2) return true;
                seen[r]=i;
                seen1[r]=true;
            } else {
                if (zerocount) return true;
                if (r==0 && s) return true;
                zerocount=1;
            }
            i++;
        }
        return false;
    }
};