class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> T(nums1.size(), *(new vector<int>(2,1)));
        T[0][0]=1;
        T[0][1]=1;
        int ans=1;
        for (int i = 1; i < nums1.size(); i++) {
            int a = nums1[i];
            if (a>=nums1[i-1]) {
                T[i][0]=max(T[i-1][0]+1,T[i][0]);
            }
            if (a>=nums2[i-1]) {
                T[i][0]=max(T[i-1][1]+1,T[i][0]);
            }
            a = nums2[i];
            if (a>=nums2[i-1]) {
                T[i][1]=max(T[i-1][1]+1,T[i][1]);
            }
            if (a>=nums1[i-1]) {
                T[i][1]=max(T[i-1][0]+1,T[i][1]);
            }
            ans=max(ans,T[i][0]);
            ans=max(ans,T[i][1]);
        }
        return ans;
    }
};