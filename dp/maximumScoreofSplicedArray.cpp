class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>> T(2,vector<int>(n));
        T[0][0]=max(nums1[0]-nums2[0],0);
        T[1][0]=max(nums2[0]-nums1[0],0);
        int a=nums1[0];
        int b=nums2[0];
        int a1=0, b1=0;
        for (int i = 1; i < n; i++) {
            a+=nums1[i]; b+=nums2[i];
            if (nums1[i]>=nums2[i] || T[0][i-1]>nums2[i]-nums1[i]) {
                T[0][i]=T[0][i-1]+nums1[i]-nums2[i];
            } else {
                T[0][i]=0;
            }
            if (nums2[i]>=nums1[i] || T[1][i-1]>nums1[i]-nums2[i]) {
                T[1][i]=T[1][i-1]+nums2[i]-nums1[i];
            } else {
                T[1][i]=0;
            }
            a1=max(a1,T[0][i]); b1=max(b1,T[1][i]);
            //cout<<a1<<", "<<b1<<"\n";
        }
        return max(a+b1, b+a1);
    }
};