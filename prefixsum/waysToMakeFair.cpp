class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> T1(nums.size());
        vector<int> T2(nums.size());
        T1[0]=nums[0];
        T2[0]=0;
        for (int i = 1; i < nums.size(); i++) {
            if (i%2==0) {
                T1[i]=T1[i-2]+nums[i];
                T2[i]=T2[i-1];
            } else {
                T2[i]=T2[max(0,i-2)]+nums[i];
                T1[i]=T1[i-1];
            }
        }
        int n = nums.size()-1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i%2==0) {
                int e = 0;
                if (i>=2) {
                    e+=T1[i-2];
                }
                e+=T2[n]-T2[max(0,i-1)];
                int o = 0;
                if (i>0) {
                    o+=T2[i-1];
                }
                o+=T1[n]-T1[i];
                if (o==e) {
                    ans++;
                }
            } else {
                int o = 0;
                if (i>1) {
                    o+=T2[i-2];
                }
                o+=T1[n]-T1[i-1];
                int e = 0;
                if (i>0) {
                    e+=T1[i-1];
                }
                e+=T2[n]-T2[i];
                if (o==e) {
                    ans++;
                }
            }
        }
        return ans;
    }
};