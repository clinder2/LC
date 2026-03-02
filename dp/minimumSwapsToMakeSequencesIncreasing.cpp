class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> T(2,*(new vector<int>(nums1.size())));
        T[0][0]=0;
        T[1][0]=1;
        for (int i =1; i < T[0].size(); i++) {
            T[0][i]=50000;
            T[1][i]=50000;
            if (nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]) {
                T[0][i]=T[0][i-1];
            }
            if (nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) {
                T[0][i]=min(T[0][i],T[1][i-1]);
            }
            if (nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) {
                T[1][i]=1+T[0][i-1];
            }
            if (nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]) {
                T[1][i]=min(T[1][i], 1+T[1][i-1]);
            }
        }
        return min(T[0].back(), T[1].back());
    }
};